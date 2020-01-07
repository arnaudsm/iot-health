from django.shortcuts import render
from django.template import loader
from django.http import HttpResponse
from django.template import loader
import json
import random
from django.views.generic import TemplateView
from chartjs.views.lines import BaseLineChartView
from random import randint
from chartjs.views.lines import BaseLineChartView

from rest_framework.views import APIView
from rest_framework.response import Response
from django.utils import timezone
import datetime
import hashlib
import json

from api.models import Point


class ChartData(APIView):
    authentication_classes = []
    permission_classes = []

    def get(self, request, format = None):
        data = {
            "labels": ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"],
            "datasets" : [
                {
            "label":"days",
            "data": random.sample(range(1,100), 7),
            }]
        }   

        return Response(data)

from rest_framework.decorators import api_view

@api_view(['POST'])
def api_post(request):
    if not request.POST.get('sensor_id'):
        return Response({"error": "No sensor specified"})

    if not request.POST.get('value'):
        return Response({"error": "No value specified"})

    point = Point(time=timezone.now(), sensor_id=request.POST.get('sensor_id'), value=request.POST.get('value'))
    point.save()

    return Response({"message": "Saved"})

@api_view(['GET'])
def api_get(request):
    if not request.GET.get('epoch_start') or not request.GET.get('epoch_end'):
        return Response({"error": "Bad epoch specified"})

    if not request.GET.get('sensor_id'):
        return Response({"error": "Sensor not specified"})

    epoch_end = datetime.datetime.fromtimestamp(int(request.GET.get('epoch_end')))
    epoch_start = datetime.datetime.fromtimestamp(int(request.GET.get('epoch_start')))
    sensor_id = int(request.GET.get('sensor_id'));


    data = {
        "labels": [],
        "datasets" : [
            {
            "label":"Sensor "+str(sensor_id),
            "data": [],
            }],
        
    }  

    points = []
    for point in Point.objects.filter(time__lte=epoch_end, time__gte=epoch_start, sensor_id=sensor_id):
        data['labels'].append(1000*int(point.time.timestamp()));
        data['datasets'][0]['data'].append(point.value);
    return Response(data)
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

import hashlib


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
def hello_world(request):
    if request.method == 'POST' and 'epoch_start' in request.data and 'epoch_end' in request.data:
        return Response({"message": "Found it"})

    if request.method == 'POST':
        return Response({"message": "Got some data!", "data": request.data})
    return Response({"message": "Hello, world!"})



hashlib.sha224(b"Nobody inspects the spammish repetition").hexdigest()
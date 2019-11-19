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

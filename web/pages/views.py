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

def index(request):
    data = random.sample(range(1,100), 7)
    context = {'data': json.dumps(data)}

    template = loader.get_template('index.html')
    return HttpResponse(template.render(context, request))


from rest_framework.views import APIView
from rest_framework.response import Response


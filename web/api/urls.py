from django.urls import path

from . import views

urlpatterns = [
    path('data/', views.ChartData.as_view()),
    path('hello/', views.hello_world),   
]
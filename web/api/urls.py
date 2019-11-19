from django.urls import path

from . import views

urlpatterns = [
    path('data/', views.ChartData.as_view()), # new
]
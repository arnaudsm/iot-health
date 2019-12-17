from django.urls import path

from . import views

urlpatterns = [
    path('data/', views.ChartData.as_view()),
    path('post/', views.api_post),   
    path('get/', views.api_get),   
]
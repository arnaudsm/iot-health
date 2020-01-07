from django.urls import path

from . import views

urlpatterns = [
    path('', views.login, name="login"),
    path('me', views.index, name='index'),
    path('mes-contacts', views.alerts, name='alerts'),
    path('patients', views.doctor, name='patients'),
    path('patients/1', views.profil, name='profil'),
    path('patients/1/alerts', views.patient_alerts, name='patient_alerts')
]
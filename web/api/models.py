from django.db import models

# Create your models here.
class Point(models.Model):
    time = models.DateTimeField('time')
    
    sensor = models.IntegerField(default=None, null=True, blank=True)
    value = models.FloatField(default=None, null=True, blank=True)

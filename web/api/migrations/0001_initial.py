# Generated by Django 2.2.8 on 2019-12-17 14:53

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='Point',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('time', models.DateTimeField(verbose_name='time')),
                ('sensor_1', models.FloatField()),
                ('sensor_2', models.FloatField()),
                ('sensor_3', models.FloatField()),
                ('sensor_4', models.FloatField()),
            ],
        ),
    ]

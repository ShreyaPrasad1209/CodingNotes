# Django
### Setup:
> virtualenv -p python .

> Scripts\activate

> pip install django==2.0.7

> mkdir src

> cd src

> django-admin startproject PROJNAME .

> python manage.py migrate

> python manage.py runserver

Run the address provided as output in web browser and setup VS Code project.

### Basic:
settings.py file has BASE_DIR which is the address of Base of the project so that we can do things relative to the src folder we created. Secret Key is project specific key. 

Apps like there's 'django.contrib.admin' which allows login and admin support just go to http://127.0.0.1:8000/admin
> python manage.py createsuperuser

Django is usefull in creating own apps
> python manage.py startapp NAMEOFAPP

An app is capable of storing data so in model.py file of new app created folder. Also add 'NAMEOFAPP' in settings.py apps section<br>
https://docs.djangoproject.com/en/2.1/ref/models/fields/

```python
from django.db import models

class Message(models.Model):
    title           = models.TextField(default='untitled')
    message         = models.TextField()
    time            = models.TextField()
```
Everytime model file is changed we need to call these two commands.

> python manage.py makemigrations

> python manage.py migrate

register app in Admin.py file
```python
from django.contrib import admin
from .models import Message

admin.site.register(Message)
```

### Creating Views App:
Creating a view like homepage. First create an app and inside it's views.py file
```python
from django.http import HttpResponse
from django.shortcuts import render

def home_view(request, *args, **kwargs):
    return HttpResponse("<h1>Hello World</h1>")
```
To make this view work we need to map it. Go to src/urls.py
```python
from django.contrib import admin
from django.urls import path
from pages.views import home_view

urlpatterns = [
    path('', home_view, name='home'),
    path('admin/', admin.site.urls),
]
```

sending HTTP Response like string isn't handy so we can create a new folder 'template' in src which will contain our html files. Then in settings.py file
```python
TEMPLATES = [
    {
        'BACKEND': 'django.template.backends.django.DjangoTemplates',
        'DIRS': [os.path.join(BASE_DIR, "templates")],
```
```python
from django.shortcuts import render

def home_view(request, *args, **kwargs):
    my_context = {
        "my_text": "Blah Blah Blah..."
    }
    return render(request, "index.html", my_context) #my_context can be left like this {}
```

### Template Inheritence:
base.html
```html
<!doctype html>
<html>
    <head>
        <title>Title</title>
    </head>
    <body>
        {% block content %}
        {% endblock %}
    </body>
<html>
```
index.html
```html
{% extends 'base.html' %}

{% block content %}
<h1>Hello {{ request.user }}!</h1>
{% endblock %}
```
> { % include 'something.html' %}

### For loop & condition in template:
```python
from django.shortcuts import render

def home_view(request, *args, **kwargs):
    my_context = {
        "list_render": 0,
        "list_items": ["First", "Second", "Third", "Fourth"]
    }
    return render(request, "index.html", my_context #my_context can be left like this {}
```
```html
{% extends 'base.html' %}

{% block content %}
<h1>Hello {{ request.user }}!</h1>
<ul>
    {% if list_render == 0 %}
        {% for my_sub_item in list_items %}
            <li>{{ forloop.counter }} - {{ my_sub_item }}</li>
        {% endfor %}
    {% else %}
        <p> Nothing to show </p>
    {% endif %}
</ul
{% endblock %}
```
https://docs.djangoproject.com/en/2.1/ref/templates/builtins/

### Render object models via templates:
In an app view.py. Here we are using this app to store a model in a database.
```python
from django.shortcuts import render, get_object_or_404
from .models import Message

def message_detail_view(request, my_id):
    #obj = Message.objects.get(id=my_id)
    obj = get_object_or_404(Message, id=my_id)
    context = {
        'obj': obj
    }
    return render(request, "chat/detail.html", context)
```
```html
Then inside the template folder at chat/detail.html
{% extends 'base.html' %}
{% block content %}
<h1>{{ obj.title }}</h1>
<h3>{{ obj.message }}</h3>
<h4>{{ obj.time }}</h4>
{% endblock %}
```
Also map the view with a URL. We can map it dynamically as above data id to be displayed is taken from url.
```python
path('chat/<int:my_id>', message_detail_view),
```

### Django Forms:
With forms user can save data to database without admin or shell. Create a new form forms.py file inside the app folder.
```python
from django import forms
from .models import Message

class MessageForm(forms.ModelForm):
    class Meta:
        model = Message
        fields = [
            'title',
            'message',
            'time'
        ]
```
Then in views.py of the app
```python
from django import forms
from .models import Message

class MessageForm(forms.ModelForm):
    class Meta:
        model = Message
        fields = [
            'title',
            'message',
            'time'
        ]
    
    def clean_title(self, *args, **kwargs):
        title = self.cleaned_data.get('title')
        if "CFE" in title:
            return title
        else:
            raise forms.ValidationError("This is not a valid title")
```
Then finally create chat/create.html template
```html
{% extends 'base.html' %}
{% block content %}
<form method='POST'> {% csrf_token %}
    {{ form.as_p }}
    <input type='submit' value='Save'/>
</form>
{% endblock %}
```
Also map the view with a URL

### Deleting object from model:
Create a view, map it with a url. In View
```python
obj = get_object_or_404(Message, id=my_id)
if request.metho == "POST":
    obj.delete()
```

### Show all:
```python
def message_all_view(request):
    queryset = Message.objects.all()
    context = {
        'object_list': queryset
    }
    return render(request, "chat/detail_all.html", context)
```
```html
{% extends 'base.html' %}
{% block content %}
{% for instance in object_list %}
    <p><a href='{{ instance.get_absolute_url }}'> {{ instance.id }} - {{ instance.title }} </a></p>
{% endfor %}
{% endblock %}
```
Inside the model add a get_absolute_url function too
```python
def get_absolute_url(self):
    return reverse("message-show", kwargs={"my_id": self.id})
    # return f"/chat/{self.id}"
```
message-show is the name assigned with url like: path('<int:my_id>/', message_detail_view, name='message-show')

### URL Namespacing:
The URLs for app can be put inside it creating urls.py file. The paths will become local to the app and an app_name can be assigned for namespace which is used in model get_absolute_url rever("chat:message-show",...) like this.
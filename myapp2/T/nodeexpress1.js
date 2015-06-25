var express = require('express');
var app = express();

var hbs = require('hbs');

app.set('view engine', 'html');
app.engine('html',hbs.__express);

app.get('/',function(request, response){
	response.render('index');
});

app.get('/about',function(request,response){
	response.render('about');
});

app.get('/article',function(request,response){
	response.render('article');
});

var server = app.listen(3000, function(){
	var host = server.address().address;
	var port = server.address().port;
	console.log('Server is up!!');
});
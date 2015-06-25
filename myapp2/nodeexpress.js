var express = require('express');
var app = express();

//app.get('/', function(request, response) {
//    response.send("This would be some HTML");
//});

app.get('/', function(request, response) {
    response.sendfile('./view/index.html');
});

app.get('/api', function(request,response){
	response.send({name:"Rajesh",age:"40",sex:"M"});
});

app.get('/about', function(request,response){
	//response.send(Math.random().toString());
	response.sendfile('./view/about.html');
});

app.get('/article', function(request,response){
	response.sendfile('./view/article.html');
)};

app.get('/', function(request, response) {
    response.send("This would be some HTML");
});

app.get('/api', function(request,response){
	response.send({name:"Rajesh",age:"40",sex:"M"});
});

app.use(function(req,res,next){
	console.log('Time:', Date.now());
	next();
});

app.use('user/:id',function(req,res,next){
	console.log('Request Type:', req.method());
	next();
}); 

app.get('user/:id',function(res,req,next){
	res.send('USER');
});

var server = app.listen(3000, function(){
	var host = server.address().address;
	var port = server.address().port;
	console.log('Server is up!!');

});

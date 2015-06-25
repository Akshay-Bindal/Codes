var express = require('express');
var app = express();

app.post('/yo', function(req, res){
	res.send('Got a Post request');
});

app.get('/', function(req, res){
	res.send('Hello World!');
});

app.use(express.static('T'));

app.put('/user', function(req, res){
	res.send('Got a PUT request at /user');
});

app.delete('/user', function(res,req){
	res.send('Got a DELETE request at /user');
});

var server = app.listen(3000, function (){
	
	var host = server.address().host;
	var port = server.address().port;
	
	console.log('Example app listenng at http://%s:%s',host,port);
});

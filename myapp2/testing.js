var express = require('express');
var path = require('path');
var app = express();
var fs = require('fs');
var util = require('util');
var EventEmitter = require('events').EventEmitter;

var Ticker = function(){
	var self = this;

	self.on('anurag', function() {
		console.log("tick");
	});
	
	self.emit('anurag');

};

app.get('/yo',function(req,res){
	console.log("inside yo");
	
	util.inherits(Ticker, EventEmitter);

	var ticker = new Ticker();
	
});

app.listen(3000);
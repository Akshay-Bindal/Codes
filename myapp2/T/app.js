var express = require('express');
var app = express();

var hbs = require('hbs');
var blogEngine = require('./BLOG');

app.set('veiw engine', 'html');
app.engine('html', hbs.__express);
app.use(express.bodyParser());

app.get('/', function(req, res){
	res.render('index',{title:"My Blog",entries:blogEngine.getBlogEntries()});
});

app.get('/about', function(req, res){
	res.render('about',{title:"About Me"});
});

app.get('/article/:id', function(req,res){
	var entry = blogEngine.getBlogEntry(req.param.id);
	res,render('aricle',{title:entry.title,blog:entry});
});

app.listen(3000);
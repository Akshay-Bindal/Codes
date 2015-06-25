var express = require('express');
var path = require('path');
var app = express();
var fs = require('fs');
var pdfdoc = require('pdfkit');
doc = new pdfdoc(); 

//var validation = require('validator');

//app.use(express.static('public'));

app.get('/',function(req,res){
	res.sendFile(__dirname+'/index.html');
});

function fun(rows)
{
	//Randomly select 7 questions from the objective_questions
	connection.query('select * from objective_questions order by rand() limit 7',function(err,data1){
		connection.query('select * from subjective_questions order by rand()limit 3',function(err,data2){
			return 
		});
	});
}


app.get('/index2',function(req,res){
	var mysql      = require('mysql');
	var connection = mysql.createConnection({
  		host     : 'localhost',
		user     : 'root',
	  	password : 'root',
	  	database : 'test'
	});
	connection.connect();
	
	var sql1 = 'select * from objective_questions order by rand() limit 7';
	connection.query(sql1,function(err,data1,fields) {
	if (!err){
	  	console.log('query successful');
	  	
	  	var ans="";
	 	
	 	for(var i = 0 ; i < 7 ; i++)
	 	{
	 		ans = ans + data1[i].Question + "\n1 " + data1[i].Opt1 + "   2 " + data1[i].Opt2 + "   3 " + data1[i].Opt3 + "   4 " + data1[i].Opt4 + "\nAnswer : " + data1[i].Answer + "\nTime : " + data1[i].time + "\n\n";
	 	}
	 			
	 	var temp = JSON.stringify(data1);
	 	
	 	var sql2 = 'select * from subjective_questions order by rand()limit 3';
	 	connection.query(sql2,function(err,data2,fields1){
	 		if(!err){
	 			console.log("hi in data2");
				for(var j = 0 ; j < 3 ; j++)
	 			{
	 				ans = ans + data2[j].Question + "\n1 " + data2[j].Opt1 + "   2 " + data2[j].Opt2 + "   3 " + data2[j].Opt3 + "   4 " + data2[j].Opt4 + "\nAnswer : " + data2[j].Answer + "\nTime : " + data2[j].time + "\n\n";
	 			}
	 			console.log(ans);
	 			connection.end();
	 			testing =fs.createWriteStream('/home/akshaybinadal/myapp/temp.pdf'); 
	 			doc.pipe(testing);
	 			doc.text(ans.toString(),10,10);
	 			doc.end();
	 			//res.send('<a href="/details">download.details</a>');

	 			testing.on('finish', function(err,data){
	 				if(!err)
	 				{
	 					var pth = __dirname + "/" + 'temp.pdf';
	 					res.setHeader('Content_Type','application/pdf');
	 					res.sendFile(pth);
	 				}
	 			});

	 	//to append data to a text file
	 			fs.appendFile('data.txt',temp,function(err,res){
	 				if(err) console.log(err);
	 			});
	 		}
	 		else
	 			console.log(err);
	 			//console.log(data2.size);
		});
	 	/*JSON.parse(temp,function(k,v){
	 		ans = ans + k+ " :  " + v + "\n"; 
	 	});
		*/
			 	

	 	//to make a pdf for temp variable 
	 	
	}
	else						
	    console.log('Error while performing Query.'+err);

});
	
	response="Form submitted";

	//to download the pdf file directly
	//res.download('/home/akshaybinadal/myapp/temp.pdf');
	
	//to open the pdf file in the browser
	/*var tempFile="/home/akshaybinadal/myapp/temp.pdf";

  	setTimeout(function(){
  			fs.readFile(tempFile, function (err,data){
    		res.contentType("application/pdf");
    		res.send(data);
    	});

  	},3000);  	*/
	//res.end(response);
});

/*app.get('/details',function(req,res){
	var tempFile="/home/akshaybinadal/myapp/temp.pdf";
  	fs.readFile(tempFile, function (err,data){
    	res.contentType("application/pdf");
    	res.send(data);
    });
});*/



app.listen(3000);

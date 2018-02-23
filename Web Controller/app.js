var express = require('express');
var bodyParser = require('body-parser');
var PythonShell = require('python-shell');

var app = express();
app.use(bodyParser.urlencoded({ extended : false }));
app.use(bodyParser.json());

app.get('/', function (req, res) {
    res.sendFile('index.html', { root: __dirname  } );
});

app.get('/index.html', function (req, res) {
    res.sendFile('index.html', { root: __dirname  } );
});

app.post('/index.html', function(req, res) {
    var flag = req.body.flag;
    var options = {
        args: [flag]
    };
    PythonShell.run('led.py', options, function (err) {
        if (err) throw err;
       	console.log('python script executed');
    });
});


server = app.listen(3000, function() {
    console.log('Server up and running...');
});
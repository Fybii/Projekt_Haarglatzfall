## node.js-App neuer HTTP Sprachen
```node.js
const http = require('http');
const PORT_NUMBER = 80;

http.createServer((request, response) => {
	//ToDo
}).listen(PORT_NUMBER)
```

### request-Objekt
```node.js
request.url : //empfangene URL
request.method : //HTTP Methode (PORT, GET, ...
request.headers : //HTTP Header
```

### response-Objekt
```node.js
response.writeHead() : //Schreibt HTTP-Header
response.write() : //HTML-dokumente
response.end() : //Beendet HTML Response
```

### URL-Routing 
```node.js
if(request.url === '/') {
...
}
if(request.url === '/login') {
...
}
```

### Formular
```html
<form method="post" action="/login">
```
**HTTP-Body:**

username = Bob 
password = secret

```node.js
if (req.url === '/login' && req.method === 'POST') {
	req.on('data', (chunk) => {
		body.push(chunk);
		});
		
	req.on('end', () => {
		bodyContent = Buffer.concat(body).toString();
	})
}

objParsedBody = queryString.parse(bodyContent);
myUsername = objParsedBody.username; //Bob



```

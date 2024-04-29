## Window-Objekt
```js
//viewport size
let myWidth = window.innerWidth; 
let myHeight = window.innerHeight; 

window.alert("Hallo!");
windown.setTimeOut(
				() => window.open('https://google.com'),
				3000);
)
```

## BOM-Objekte
1. **location-Objekt**:
	- Enthält **Info** zur **aktuellen URL**
```js
alert(location.origin); //URL = Protokoll, IP,port
alert(location.href); //URL
location.replace('https://www.example');
```

2. **console-Objekt**
```js
console.log('Ein Test...');
console.error('Ein Fehler...');
console.warn('Eine Warnung...');
```

3. **navigator-Objekt**
	- **Status** und **zur Identität User Agent**
```js
navigator.userAgent;
navigator.plugins;
navigator.cookieEnable;
navigator.geolocation.getCurrentPosition(showPosition);
```

## LocalStorage-Objekt
```js
"key": "Wert"
```
- **Schlüssel-Wert-Paare** werden permanent angesprochen.

```js
localStorage.setItem('Alice', '12078');
let creditNr = localStorage.getItem('Alice');
```

## SessionStorage-Objekt
- **Wird beim Schliessen** des **Browser-Tabs** gelöscht.
- Ist **temporär, lokal und verschlüsselt**
```js
sessionStorage.setItem('ID', '1234');
sessionStorage.getItem('ID');
```

## History-Objekt
- **History Objekt** speichert die **Browser-History**
```js
history.forward();
history.back();
```
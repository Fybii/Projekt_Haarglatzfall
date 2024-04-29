# alert

# console.log

# document.

### document.getElementById

### document.getElementsByClassName

### document.forms

### document.images

### document.links

### document.write

# DOM-Quoires
```js
//1. ID Selector:
const obj = document.getElementById("myID");
//-------------------------------------------------//
//2. Class Selector:
const elementHTMLCollection = document.getElementsByClassName("important");
for (let element of elementsHTMLCollection) {
	console.log(element.nodeName);
}
element0 = elementsHTMLCollection[0];
element0 = elementsHTMLCollection.item(0);
element = elementsHTMLCollection.namedItem("myID");
//---------------------------------------------------//
//3. CSS-Selector:
```
```html
<p class="c1">, <h1 class="c1">
```
```js
//gibt das erste Element im Dokument zurück
let elem = document.querySelector('p.c1');
```
```html
<p class="c1">, <h1 class="c1">
```
```js
let elements = document.querySelectorAll('c1');
elements.forEach(item => console.log(item));
//-------------------------------------------------//
//4. Tag-Selector
const attlist = document.getElementByTagName('article');
myArticle = attlist[0];
const firstSiblingArticle = myArticle.nextSibling;
if(firstSiblingArticle.nodeName === 'article') {
	firstSiblingArticle.className = "text--content";
	}
else {
	...
	}
```

# .innerHTML

# .innerText

# .lenght()

# .push()

# .pop()

# .split()

# .toLowerCase()

# .toUpperCase()

## .trim()
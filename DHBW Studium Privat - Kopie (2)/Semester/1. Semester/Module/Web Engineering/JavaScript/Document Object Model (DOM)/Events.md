- **Events** sind **Ereignisse**: Mausklick, Tastatureingabe, laden eines Bildes/Dokuments.
- Ein **Element kann auch** für ein **bestimmtes Registrieren** (**Event Handles**)
- Beim **Auftreten** der **Events** kann eine **Callback-Fkt. gestartet werden**

## Wo können Event-Handler angelegt werden.
1. **JavaScript-Code: Good Practice**
2. **HTML-Code: Bad Practice**

## Event-Handler in JavaScript-Code
```html
<button id ="btn" value="Hover me"></button>

<script>
	btn = document.getElementById('btn');
	btn.addEventListener('mouseover', hoverMe, false);
	
	function hoverMe () {
		btn.style.backgroundcolor = "blue";
	}
</script>
```

`<script> ... </script>` =
```js
btn.addEventListener('mouseover',
					() => {btn.style.backgroundcolor = "blue"},
					false);
```

### Login-Form
```js
const objForm = document.forms.loginForm; //login Form: name-Attribut
const objButton = objForm.elements.loginButton; //loginButton: name-Attribut

objButton.addEventListener('click',
						  () => {
						  let myUserName = objForm.elements.userName;
						  //ToDo m<UserName
						  },
						  false);
```

### this-KeyWord
- **this** ist auf das **aktuelle Objekte referenziert**.
```js
btn.addEventListener('click',
					() => {
						alert('Tag: ' + this.tagName)
						},
						false);
```

## Event Objekt

- **Event Objekt** wird an den **EventListener** abgegeben, und **beschreibt** die **Details eines Events**:
```js
event.type: HTML, DOM Event
			(click, mouseover, keypress,...)
```
```js
event.currentTarget: auslöse Element (button)
```
```js
event.clientx, event.clienty: Position der Maus in x- und y-Richtung
```
```js
event.key: gedrückte Keyboardtaste
```
```js
event.buttons: gedrückte Maustaste
```
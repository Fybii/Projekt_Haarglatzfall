## switch()
```js
switch(expression) {
	case ausdruck1:
		//ToDo
		break;
		
	case ausdruck2;
		//ToDo
		break;
		
	default: 
		//ToDo
}
```

### Beispiel
```js
const user {
			firstName: "Paul";
			lastName: "Breitner"
}
```

```js
switch(true) {
	case(user === undefined):
		console.log('User not defined');
		break;
		
	case(user.firstName === undefined || user.lastName ===
										 undefined);
		console.log('User first or last Name not defined');
		break;

	default:
		return: user;
}
```
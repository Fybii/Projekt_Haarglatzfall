- **JSON** dient zum **Austausch** von **Daten zwischen** dem **Webserver** und dem **Webbrowser**.
- Dazu wird ein **JavaScript serialisiert**, d.h. in einen **JSON-String** umgewandelt.

```js
const objJohn = {
				firstName: "John",
				lastName: "Doe",
				id: 5566,
				fullName: function() {
							return this.firstname
							+ ""
							+ this.lastname;
							}
				}

//Server
//{"firstname": "John", "lastname":"Doe", "id": 5566}
let jsonString = JSON.stringify(objJohn);

//Client:
const objJohn = JSON.parse(jsonString);
```


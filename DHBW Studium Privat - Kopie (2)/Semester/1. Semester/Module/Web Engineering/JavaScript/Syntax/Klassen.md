- Mittels dem **Keyword** `class` können Sie eine Vorlage für eine bestimmte "**Personengruppe**" generieren.

## Beispiel für Personen
```js
class Person {
	constructor(vName, nName) {
		this.firstName = vName;
		this.lastName = nName;
	}
	fullName() {...};
}

const objJohn = new Person("John", "Doe");
```

### Vererbungen
```js
class.itPro extends Person {
	constructor(job, skills, department,
				vName, nName) {
		/*
		Aufrufen des constructors aus der als extends
		angegebenen Klasse
		*/
		super(vName, nName);
		this.job = job;
		this.skills = skills;
		this.department = department;
	}
}

const itProBob = new itPro("Admin", ["html", "css"], "Dev",
						   "Bob", "Taylor")
```
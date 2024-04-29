![[Pasted image 20240116143538.png]]

![[Pasted image 20240116143603.png]]
## XML Aufbau

### XML Prolog
- Metainformation im Prolog

```XML
<?xml version="1.0" encoding="UTF-8" ?>
<!DOCType note SYSTEM "note.dtd"> 
```

### XML Body

```xml
<note severity="Top Secret" date="15.01.2024">
	<to> Bob </to>
	<from> Alice </from>
	<heading> Reminder </heading>
	<body> Hallo Bob, wir sehen uns morgen </body>
	<footer>&mfg;</footer>
</note>
```

```XML
<note seventy="Top Secret">

Text oder andere Elemente

</note>
```

**Leeres Element**:
```XML
<note></note>
<note/>
```

**Kommentar:**
```XML
<!-- ....................................................................................................................
-->
```

## Regeln 

- Namen sind **case-sensitive**.
- Namen mit **Buchstaben** beginnen.
- Im Namen keine Leerzeichen.

## 2 Begriffe:

- **well-formed** XML dokumente
	- konkrete Syntax

- **gültige XML-Dokumente**
	- + **well-formed**
	- + **DTD muss erfüllt sein!**

## Entitäten

- Mittels Entitäten können Textbausteine abgekürzt werden.
	- BSP: `<!Entity>`

- vordefinierte Entitäten
```
&lt; <
&gt; >
&amp; &
&apos; '
&quot; "
```

## NMTOKEN

- keine Leerzeichen
- keine Kommas
- Buchstaben
- '.'
- '\_'
- '-'
## Beispiel: note.dtd

```DTD
<!ELEMENT note (to, from, heading, body)>
<!ELEMENT to (#PCDATA)>
<!ELEMENT from (#PCDATA)>
<!ELEMENT heading (#PCDATA)>
<!ELEMENT body (#PCDATA)>
<!ELEMENT footer (#PCDATA)>
<!ENTITY mfg "Mit freundlichen Grüßen">
<!ATTLIST note
	severity CDATA #Required
	date NMTOKEN
\>

```

- \#PCDATA (Parsed Character Data)
	- Textdaten die der XML-Parser parsed!

![[Pasted image 20240116151920.png]]

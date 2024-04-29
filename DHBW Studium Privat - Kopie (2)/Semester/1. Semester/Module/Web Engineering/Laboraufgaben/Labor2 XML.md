## Aufgabe 1.1
### Aufgabe 1.1.1
Ein Namespace in XML wird verwendet, um Datenkonflikte, beim Verknüpfen verschiedener XML Dokumente zu vermeiden.
- Folgendes Beispiel:
```XML
<table>
<tr>
<td>Äpfel</td>
<td>Bananen</td>
</tr>
</table>
```

```XML
<table>
<name>Brett</name>
<breite>120</breite>
<länge>200</länge>
</table>
```
- Diese beiden XML Dokumente tragen beide HTML Tabellen in sich
	Sollten diese Beiden XML Fragmente verbunden werden, würde es zu einem Namenskonflikt kommen, da beide Dateien den Namen "`<table>`" enthalten.

- Durch Namespaces kann dieses Problem nun gelöst werden, indem man den Inhalten Prefixe gibt.
	Beispiel `<h:table>` 

- Nun muss man nur noch den Namespace deklarieren über:
```XML
<h:table xmlns:h="URI">
```

- So können nun die Tabellen auseinandergehalten werden und beide miteinander Verknüpft werden.

### Aufgabe 1.1.2
![[Pasted image 20240206143205.png]]
## Aufgabe 1.2

### Aufgabe 1.2.1
![[Pasted image 20240207114819.png]]


## Aufgabe 2.1
![[Pasted image 20240207121644.png]]
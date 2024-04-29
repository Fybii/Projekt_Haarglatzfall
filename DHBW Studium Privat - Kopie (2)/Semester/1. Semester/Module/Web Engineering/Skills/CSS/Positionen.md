## Positions


```css
.item-1 {
position absolute;
/*"removes the item from the document"
"position unlocks:"*/
top: ; /*position on top of the document*/
right: ; /*position on right of the document*/
left: ; /*position on left of the document*/
bottom: ; /*position on bottom of the document*/ 
}
```

- Das Objekt wird relativ zur gesamten HTML genommen, da kein parent eine Position property besitzt.

```css
.container {
position: relative;
}

.item-1 {
position absolute;
/*"removes the item from the document"
"position unlocks:"*/
top: ; /*position on top of the document*/
right: ; /*position on right of the document*/
left: ; /*position on left of the document*/
bottom: ; /*position on bottom of the document*/ 
}
```

- Das Objekt wird relativ zu seinem parent genommen.

## z-index

```css
.item-1 {
z-index: -1; 
/*sets the object in the background of the rest of his parent*/
}
```
```js
if(saldo < 0) {
	msg = "Transaktion nicht erlaubt";
} else if(saldo === 0) {
	msg = "Konto auf null";
} else {
	msg = "Transaktion erlaubt";
}

- **break** kann eine Schleife **unterbrechen**
- **continue** kann eine **Wiederholung überspringen**

```c++
//continue
for(int i = 1; i <= 20, i++) {
	if(i == 13) {
		break
	}
	std::cout << i << '\n';
}
//Output
1
2
3
4
5
6
7
8
9
10
11
12
//Stoppt nach 13
```

```c++
for(i = 1; i <= 20; i++) {
	if(i == 13) {
		continue
	}
	std::cout << i << '\n';
}
//Output:
1
2
3
4
5
6
7
8
9
10
11
12
14
15
16
17
18
19
20
//skipt 13
```
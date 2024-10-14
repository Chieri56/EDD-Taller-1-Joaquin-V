# EDD-Taller-1-Joaquin-V
Integrante: Joaquin Vega, 21.638.105-K, joaquin.vega02@alumnos.ucn.cl, C2

Al inicio se crea el array de la biblioteca (100) junto con el de usuarios (5). Tambien se hacen 2 variables staticas, bibl y usrs, las cuales son para saber cuantos libros hay en el array de biblioteca
y cuantos usuarios en el array de usuarios respectivamente y no tener problemas con nullptr al invocar funciones

Luego se ejecuta un menu con las opciones:
1. Agregar material
2. Informacion de la biblioteca
3. Buscar material
4. Prestar o devolver (se realiza un login)
5. Gestion de usuarios
6. Terminar ejecucion

La funcion menu hace el cout de las opciones y retorna la opcion que se escoje

La funcion agregarMaterial crea y añade un libro o revista al array de biblioteca

La funcion informacionBiblioteca imprime todos los libros y revistas que se encuentras en el array biblioteca

La funcion buscarMaterial tiene 2 funciones, si el bool es falso simplemente busca el libro o revista por titulo o autor y los imprime en pantalla, mientras que si el bool es true,
hace seleccionar algun libro o revista que se haya encontrado y lo retorna

La funcion prestarDevolver hace escojer entre ambas opciones y hace las funciones respectivas

La funcion gestionUsuarios hace escojar entre crear, buscar o eliminar un usuario y hace la funcion respectiva

La funcion login busca un usuario por ID y hace seleccionar a alguno que se haya encontrado con la misma ID y al seleccionar seria el loggearse con ese usuario

La funcion escribir y lectura no estan completas

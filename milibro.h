//MI LIBRERIA DE FUNCIONES

//FUNCION PARA CALCULAR UNA NOTA DEFINITIVA
float calcula_definitiva(float nota1, float nota2, float nota3, float nota4)
{
	float definitiva;
	
	definitiva = nota1*0.3 + nota2*0.3 + nota3*0.3 + nota4*0.1;
	
	return definitiva;
}

//FUNCION PARA CALCULAR EL SALARIO DE UN EMPLEADO
long calcula_salario(long nhoras, long valorh)
{
	return nhoras*valorh;
}

//FUNCION PARA CALCULAR EL AREA DE UN RECTANGULO
long area_rectangulo(long largo, long ancho)
{
	return largo*ancho;
}

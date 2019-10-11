/*
 * cliente.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "plasticos.h"
#include "utn.h"


static int generarId(void)
{
	static int id = 0;
	id++;
	return id;
}
int initLugarLibreCliente(struct sCliente *aArray, int cantidad)
{
	int retorno = -1;
	int i;
	if(aArray!=NULL && cantidad>0){
		for(i=0;i<cantidad;i++){
			aArray[i].status = STATUS_EMPTY;
		}
		retorno = 0;
	}
	return retorno;
}
int ordenarArrayCliente(struct sCliente *aArray, int cantidad){
	int i;
	int retorno = -1;
	struct sCliente bCliente;
	int fSwap;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		do
		{
			fSwap = 0;
			for(i=0;i<cantidad-1;i++)
			{
				if(strncmp(aArray[i].nombreEmpresa,aArray[i+1].nombreEmpresa,QTY_CARACTERES)>0)
				{
					fSwap = 1;
					bCliente = aArray[i];
					aArray[i]=aArray[i+1];
					aArray[i+1]=bCliente;
				}
			}
		}while(fSwap);
	}
	return retorno;
}
int imprimirArrayCliente(struct sCliente *aArray, int cantidad, struct sPedidosRecoleccion *aPedidos, int cantidadPedidos){
	int i;
	int retorno = 0;
	int contadorPedidos = 0;
	int j;
	if(aArray != NULL && cantidad>0 && aPedidos !=NULL)
	{
		for(j=0;j<cantidadPedidos;j++){
				if(aPedidos[j].status == STATUS_PENDING)
				{
					contadorPedidos++;
				}
		}
		printf("Clientes:\n");
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_NOT_EMPTY){
				printf("Id: %d - Nombre: %s - Direccion: %s - Cuit: %s - Localidad: %s - Pedidos de Recoleccion: %d\n"
						,aArray[i].idCliente,aArray[i].nombreEmpresa,aArray[i].direccion,aArray[i].cuit,aArray[i].localidad,contadorPedidos);
			}
		}
	}
	return retorno;
}
int buscarLugarLibreCliente(struct sCliente *aArray, int cantidad)
{
	int retorno = -1;
	int i;
	if(aArray!=NULL && cantidad>0){
		for(i=0;i<cantidad;i++){
			if(aArray[i].status == STATUS_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int buscarClientePorId(struct sCliente *aArray,int cantidad,int id){
	int retorno = -1;
	int i;
	if(aArray!=NULL && cantidad>0){
		for(i=0;i<cantidad;i++){
			if(aArray[i].idCliente==id && aArray[i].status == STATUS_NOT_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int altaClientePorId(struct sCliente *aArray, int cantidad,struct sCliente cliente,int index)
{
	int retorno = -1;
	cliente.idCliente = generarId();
	if(aArray!=NULL && cantidad>0){
		if(index>=0){
				retorno = 0;
				aArray[index] = cliente;
				aArray[index].status = STATUS_NOT_EMPTY;
		}
	}
	return retorno;
}
int verificarBajaCliente(void){
	int retorno = -1;
	char respuesta;
	getChar(&respuesta,"Esta seguro que desea dar la baja? s/n \n","Error\n",'a','z',0);
	if(respuesta=='s'){
		retorno = 0;
		}else if (respuesta=='n'){
			retorno = 1;
		}else {
			retorno = -1;
		}
	return retorno;
	}

int bajaClientePorId(struct sCliente *aArray, int cantidad,int id)
{
	int retorno = -1;
	int indice = buscarClientePorId(aArray,cantidad,id);
	if(verificarBajaCliente()==0){
		if(aArray!=NULL && cantidad>0){
			if(indice>=0){
				retorno = 0;
				aArray[indice].status = STATUS_EMPTY;
			}
		}
	}
	return retorno;
}
int modificarClientePorId(struct sCliente *aArray,int cantidad,struct sCliente cliente)
{
	int retorno = -1;
	if(aArray!=NULL && cantidad > 0){
	int posicion =buscarClientePorId(aArray,cantidad,cliente.idCliente);
		if (posicion >= 0){
			aArray[posicion] = cliente;
			aArray[posicion].status = STATUS_NOT_EMPTY;
		}
	}
	return retorno;
}
int pedirDatosCliente(struct sCliente* pCliente)
{
	int retorno = -1;
	struct sCliente bCliente;
	getString(bCliente.nombreEmpresa,"Ingrese nombre de la empresa: \n","Error",3,50,2);
	getString(bCliente.direccion,"Ingrese direccion: \n","Error",0,50,2);
	getString(bCliente.cuit,"Ingrese cuit: \n","Error. Ingrese cuit valido (11 numeros)\n",11,11,2);
	getString(bCliente.localidad,"Ingrese localidad :\n","Error",2,50,2);
	*pCliente = bCliente;
	return retorno;
}

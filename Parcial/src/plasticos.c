/*
 * plasticos.c
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */


#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "plasticos.h"
#include "utn.h"

static int generarId(void)
{
	static int id = 0;
	id++;
	return id;
}
int initLugarLibrePedido(struct sPedidosRecoleccion *aArray, int cantidad)
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

int imprimirArrayPedido(struct sPedidosRecoleccion *aArray, int cantidad){
	int i;
	int retorno = -1;
	if(aArray != NULL && cantidad>0)
	{
		retorno = 0;
		printf("Pedidos:\n");
		for(i=0;i<cantidad;i++)
		{
			if(aArray[i].status == STATUS_NOT_EMPTY){
				//printf("Id: %d - Cuit cliente: %s - Direccion cliente: %s - Cantidad de kilos %f\n",);
			}
		}
	}
	return retorno;
}
int buscarLugarLibrePedido(struct sPedidosRecoleccion *aArray, int cantidad)
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
int buscarPedidoPorId(struct sPedidosRecoleccion *aArray,int cantidad,int id){
	int retorno = -1;
	int i;
	if(aArray!=NULL && cantidad>0){
		for(i=0;i<cantidad;i++){
			if(aArray[i].idPedidos==id && aArray[i].status == STATUS_NOT_EMPTY){
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int altaPedidoPorId(struct sPedidosRecoleccion *aArray, int cantidad,struct sPedidosRecoleccion pedido,int index,int idCliente)
{
	int retorno = -1;
	pedido.idPedidos = generarId();
	if(aArray!=NULL && cantidad>0){
		if(index>=0){
				retorno = 0;
				aArray[index] = pedido;
				aArray[index].status = STATUS_PENDING;
				aArray[index].idCliente = idCliente;
		}
	}
	return retorno;
}
int verificarBajaPedido(void){
	int retorno = -1;
	char respuesta;
	getChar(&respuesta,"Esta seguro que desea dar la baja? s/n \n","Error\n",'a','z',0);
	if(respuesta=='s'){
		retorno = 0;
		}else if (respuesta=='n'){
			retorno = 1;
		} else {
			retorno = -1;
		}
	return retorno;
	}

int bajaPedidoPorId(struct sPedidosRecoleccion *aArray, int cantidad,int id)
{
	int retorno = -1;
	int indice = buscarPedidoPorId(aArray,cantidad,id);
	if(verificarBajaPedido()==0){
		if(aArray!=NULL && cantidad>0){
			if(indice>=0){
				retorno = 0;
				aArray[indice].status = STATUS_EMPTY;
			}
		}
	}
	return retorno;
}
int modificarPedidoPorId(struct sPedidosRecoleccion *aArray,int cantidad,struct sPedidosRecoleccion pedido)
{
	int retorno = -1;
	if(aArray!=NULL && cantidad > 0){

	int posicion =buscarPedidoPorId(aArray,cantidad,pedido.idPedidos);
		if (posicion >= 0){
			aArray[posicion] = pedido;
			aArray[posicion].status = STATUS_NOT_EMPTY;
		}
	}
	return retorno;
}
int pedirTipoPedido(struct sPedidosRecoleccion* pPedido)
{
	int retorno = -1;
	struct sPedidosRecoleccion bPedido;
	getFloat(&bPedido.residuoHDPE,"Ingrese la cantidad de kilos de HDPE","Error",0,1000000000000,2);
	getFloat(&bPedido.residuoLDPE,"Ingrese la cantidad de kilos de LDPE","Error",0,1000000000000,2);
	getFloat(&bPedido.residuoPP,"Ingrese la cantidad de kilos de PP","Error",0,1000000000000,2);
	*pPedido = bPedido;
	return retorno;
}
int pedirDatoPedido(struct sPedidosRecoleccion* pPedido)
{
	int retorno = -1;
	struct sPedidosRecoleccion bPedido;
	getFloat(&bPedido.pesoTotal,"Ingrese la cantidad de kilos a recolectar","Error",0,10000000000,2);
	*pPedido = bPedido;
	return retorno;
}


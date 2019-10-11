/*
 * cliente.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef CLIENTE_H_
#define CLIENTE_H_
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1
#define STATUS_PENDING 2
#define QTY_CLIENTES 100
#define QTY_CARACTERES 50
#include "plasticos.h"

struct sCliente{
	int idCliente;
	int status;

	char nombreEmpresa[50];
	char direccion[50];
	char cuit[50];
	char localidad[50];
};
int modificarClientePorId(struct sCliente *aArray,int cantidad,struct sCliente cliente);
int initLugarLibreCliente(struct sCliente *aArray, int cantidad);
int imprimirArrayCliente(struct sCliente *aArray, int cantidad,struct sPedidosRecoleccion *aPedidos,int cantidadPedidos);
int buscarLugarLibreCliente(struct sCliente *aArray, int cantidad);
int buscarClientePorId(struct sCliente *aArray,int cantidad,int id);
int altaClientePorId(struct sCliente *aArray, int cantidad,struct sCliente cliente,int index);
int bajaClientePorId(struct sCliente *aArray, int cantidad,int id);
int pedirDatosCliente(struct sCliente* pCliente);


#endif /* CLIENTE_H_ */

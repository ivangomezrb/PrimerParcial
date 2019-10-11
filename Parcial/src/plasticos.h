/*
 * plasticos.h
 *
 *  Created on: 10 oct. 2019
 *      Author: alumno
 */

#ifndef PLASTICOS_H_
#define PLASTICOS_H_
#define STATUS_EMPTY 0
#define STATUS_NOT_EMPTY 1
#define STATUS_PENDING 2
#define QTY_CARACTERES 50
#define QTY_PEDIDOS 1000

struct sPedidosRecoleccion{
	int idPedidos;
	int status;

	float pesoTotal;
	float residuoHDPE;
	float residuoLDPE;
	float residuoPP;
	int idCliente;
};
int modificarPedidoPorId(struct sPedidosRecoleccion *aArray,int cantidad,struct sPedidosRecoleccion pedido);
int initLugarLibrePedido(struct sPedidosRecoleccion *aArray, int cantidad);
int imprimirArrayPedido(struct sPedidosRecoleccion *aArray, int cantidad);
int buscarLugarLibrePedido(struct sPedidosRecoleccion *aArray, int cantidad);
int buscarPedidoPorId(struct sPedidosRecoleccion *aArray,int cantidad,int id);
int altaPedidoPorId(struct sPedidosRecoleccion *aArray, int cantidad,struct sPedidosRecoleccion pedido,int index,int idCliente);
int bajaPedidoPorId(struct sPedidosRecoleccion *aArray, int cantidad,int id);
int pedirDatoPedido(struct sPedidosRecoleccion* pPedido);

#endif /* PLASTICOS_H_ */

#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "cliente.h"
#include "plasticos.h"

int main(void)
{
	int option;
	int bIdCliente;
	int flagSeCreaCliente = 0;
//	int bIdPublicidad;
	struct sCliente aCliente[QTY_CLIENTES];
	struct sCliente bCliente;
	struct sPedidosRecoleccion aPedidosRecoleccion[QTY_PEDIDOS];
	struct sPedidosRecoleccion bPedidosRecoleccion;
	initLugarLibreCliente(aCliente,QTY_CLIENTES);
	initLugarLibrePedido(aPedidosRecoleccion,QTY_PEDIDOS);
	do{
		printf("1) Alta de clientes.\n");
		printf("2) Modificacion de clientes.\n");
		printf("3) Baja de clientes.\n");
		printf("4) Crear pedido de recoleccion.\n");
		printf("5) Procesar residuos.\n");
		printf("6) Imprimir clientes.\n");
		printf("7) Imprimir pedidos pendientes.\n");
		printf("8) Imprimir pedidos procesados.\n");
		printf("9) Salir.\n");
		getInt(&option,"Ingrese una opcion.\n","Error. Opcion inválida\n",0,9,3);
		switch (option)
		{
			case 1: if( buscarLugarLibreCliente(aCliente,QTY_CLIENTES)>=0)
				{
					int index = buscarLugarLibreCliente(aCliente,QTY_CLIENTES);
					pedirDatosCliente(&bCliente);
					altaClientePorId(aCliente,QTY_CLIENTES,bCliente,index);
					flagSeCreaCliente = 1;
				}else{
					printf("No hay mas lugar libre.\n");
				}
					break;
			case 2:	imprimirArrayCliente(aCliente, QTY_CLIENTES,aPedidosRecoleccion,QTY_PEDIDOS);
					getInt(&bIdCliente,"Ingrese un ID para modificar:\n","Error\n",0,1000,2);
					pedirDatosCliente(&bCliente);
					bCliente.idCliente = bIdCliente;
					modificarClientePorId(aCliente,QTY_CLIENTES,bCliente);
					break;
			case 3:	imprimirArrayCliente(aCliente, QTY_CLIENTES,aPedidosRecoleccion,QTY_PEDIDOS);
					getInt(&bIdCliente,"Ingrese un ID para dar de baja:\n","Error. Ingrese un id valido\n",0,1000,2);
					if(bajaClientePorId(aCliente,QTY_CLIENTES,bIdCliente) == -1)
					{
						printf("Opcion incorrecta.\n");
					}
					break;
			case 4:	if(flagSeCreaCliente == 1){
					imprimirArrayCliente(aCliente, QTY_CLIENTES,aPedidosRecoleccion,QTY_PEDIDOS);
					getInt(&bIdCliente,"Ingrese un id de Cliente\n","Error.\n",0,1000,2);
					if(buscarClientePorId(aCliente,QTY_CLIENTES,bIdCliente)>=0)
					{
						if(buscarLugarLibrePedido(aPedidosRecoleccion,QTY_PEDIDOS)>=0){
							int indexPedido = buscarLugarLibrePedido(aPedidosRecoleccion,QTY_PEDIDOS);
							pedirDatoPedido(&bPedidosRecoleccion);
							altaPedidoPorId(aPedidosRecoleccion,QTY_PEDIDOS,bPedidosRecoleccion,indexPedido,bIdCliente);
						}else{
							printf("No hay mas lugar para pedidos.\n");
						}
					}else{
						printf("Error. Ingrese un id correcto\n");
					}
				}else{
				printf("Error. Debe ingresar un cliente antes.\n");
				}
					break;
			case 5: if(flagSeCreaCliente == 1){

					}else{
					printf("Error. Debe ingresar un cliente antes.\n");
					}
					break;
			case 6:	imprimirArrayCliente(aCliente, QTY_CLIENTES,aPedidosRecoleccion,QTY_PEDIDOS);
					break;/*
			case 7: getString(&cuit,"Ingrese Cuit","Error",0,99999999,2);
					consultaFacturacion(aPantalla,QTY_PANTALLAS,aPublicidad,QTY_PUBLICIDADES,&cuit);
					break;
			case 8:	imprimirArrayPublicidad(aPublicidad,QTY_PUBLICIDADES);
					break;*/
			case 9:
					break;
		}
	}while(option!=9);
	return EXIT_SUCCESS;
}

/* 
 *  
 *  Este código é destinado a comutação dos relés de um módulo contendo dois canais por meio de chaves Push Bottom 
 *  Benedito Lucas de Toledo 
 *  DATA 01/06/2022
 *  ELETROKITS :  https://lista.mercadolivre.com.br/_CustId_325367602?item_id=MLB2659424372&category_id=MLB99779&seller_id=325367602&client=recoview-selleritems&recos_listing=true
 *  Youtube: https://www.youtube.com/channel/UCR_RgvW4hls1Q76Um_8IIjw
 *  GITHUB:  https://github.com/BeneditoLT
 */

//Definições de pinos de entrada e saída 

#define BOTAO_1 5 //Botão 1 ligado ao pino 5
#define BOTAO_2 4 //Botão 2 ligado ao pino 4
#define RELE_1 50 // Relé 1 ligado ao pino 50
#define RELE_2 51 // Relé 1 ligado ao pino 51


// Definições de variáveis globais 

int STrele1 = 1;
int STrele2 = 1;
int BT1status = 1;
int BT2status = 1;

//Bloco de configuração

void setup() {
  pinMode (BOTAO_1, INPUT);
  pinMode (BOTAO_2, INPUT);
  pinMode (RELE_1, OUTPUT);  //Obs.: a lógica de atuação do módulo relé é negativa, portanto, quanto a DDP entre o pino 50 ou 51 e o GND é 5V o canal está "Desligado" ou aberto
  pinMode (RELE_2, OUTPUT);
  digitalWrite(RELE_1, 1);  //Colocamos a lógica do relé em estado alto "5V" para que os canais iniciam desligado 
  digitalWrite(RELE_2, 1);
}


void loop() { // Main loop


  if (digitalRead(BOTAO_1) == 0 && BT1status == 1) { //Verificar se o botão foi pressionado e o estado do filtro digital "BTstatus"
    STrele1 =  !STrele1;                             //Inverter o estado do relé 
    delay(20);                                       // 
    digitalWrite(RELE_1, STrele1);                   // Enviar a informação ao relé 
    BT1status = 0;                                   // Mudar o estado do filtro para não repetir o ciclo  


  }
  

  if (digitalRead(BOTAO_2) == 0 && BT2status == 1) {  //Verificar se o botão foi pressionado e o estado do filtro digital "BTstatus"
    STrele2 =  !STrele2;                              //Inverter o estado do relé 
    delay(20); 
    digitalWrite(RELE_2, STrele2);                    // Enviar a informação ao relé 
    BT2status = 0;                                    // Mudar o estado do filtro para não repetir o ciclo  



  }
  if (digitalRead(BOTAO_1) == 1  ) {                  // Verificar se o botão foi liberado

    BT1status = 1;                                    // Mudar o estado do filtro  
  }
  if (digitalRead(BOTAO_2) == 1  ) {                  // Verificar se o botão foi liberado

    BT2status = 1;                                   // Mudar o estado do filtro  
  }


}

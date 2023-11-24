Projeto desenvolvido à Global Solution por:
Bryan Willian Messias Barbosa (RM:551305) e 
Guilherme Gonçalves Calil Daher (RM:98611)  para a disciplina de Edge Computing and Computer Systems do professor Airton Yassushiko Coppini Toyofuku.

 <h1 style="font-size: 2em;">Uma breve descrição do problema de saúde abordado:</h1>

O tema proposto na Global Solution deste semestre envolve o uso da tecnologia com a saúde, como meios provenientes para promover um facilitador de acesso da população aos serviços prestados por profissionais da saúde. Diante os temas propostos pelos organizadores do projeto na FIAP, decidimos que iremos abordar o tema: Controle de Doenças Transmissíveis com ênfase em DSTs (doenças sexualmente transmissíveis). 

<h1 style="font-size: 2em;">Uma visão geral da solução proposta. </h1>

Nossa solução abrange diversos quesitos, primeiramente, a fim de conscientizar e ampliar o conhecimento das pessoas, desenvolveremos um site informativo explicando detalhadamente no que se diz a respeito às DSTs. Auxiliando na informação, adicionaremos a uma das páginas do site um guia/mapa sinalizando todos os postos de saúde e linhas de metrô que garantem o acesso gratuito aos preservativos por toda grande São Paulo. Outra aba será disponibilizada para o tratamento de dúvidas e perguntas frequentes a respeito de saúde sexual, que dessa forma auxiliará numa melhora na qualidade de vida e consciência sobre o assunto. O foco principal da nossa plataforma Web é garantir uma melhora na qualidade de vida da população, mas de que jeito? Simples! Informando, conscientizando, potencializando a qualidade de vida e por fim, acabando com os estigmas tabus ainda remanescentes na sociedade. 


# Instruções claras sobre como configurar e executar a aplicação.
 

Na página do projeto do Wokwi, o main code estará ao lado esquerdo e os hardwares à direita.  
Para garantir que haja a aplicação, só basta clicar no botão “Start Simulation”. 
Após clicar, espere algo em torno de 40s e passado este tempo o código e suas funcionalidades estarão sendo executados.  
Ajuste no Ultrassonic Distance Sensor o valor desejado e faça o mesmo com o DHT22. 
Após alguns segundos da execução aparecerá as seguintes mensagens: “Conectando Wifi”, “...Conectado!” e “Conectando com o broker MQTT”. 
De acordo com os valores escolhidos manualmente, estes valores serão exibidos tanto na parte inferior da página quanto no LCD16x2. 
Todas estas informações serão enviadas diretamente para a plataforma “TAGO”, basta somente clicar em Buckets -> #Device1 -> Variables. 
Todos os valores escolhidos manualmente nos hardwares serão direcionados à plataforma, mostrando os números escolhidos, que neste caso seriam: (Distância, Umidade e Temperatura) 

Foram utilizados no projeto: 
Plataformas: Wokwi e TAGO 
Hardware: ESP32, DHT22, LCD16x2, Cabos, GND Symbol, VCC Symbol, Ultrassonic Distance Sensor 

Link para a simulação do projeto na Wokwi: https://wokwi.com/projects/382120077112087553
link para o vídeo da simulação: https://youtu.be/5Cx0FjwMVZg
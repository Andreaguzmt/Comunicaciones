clear all;
close all;
clc;
disp('inicio');
muestras=1000;
delete(instrfind(('Port'),('COM4')));
s=serial('COM4','BaudRate',9600,'Terminator','CR/LF');
fopen(s);
pause(1);
disp('puerto abierto');
%Creaciom de variables en matriz
v1=zeros;
v2=zeros;
v3=zeros;
voltaje=zeros(zeros,3);
figure('Name','Frafica determinante de los tres valores');
title('Grafica ADC');
xlabel('muestras');
ylabel('Voltajes (V)');
grid off;
hold on;
%plot de señales
for c=1:1:muestras
    fprintf(s,'%c','d');
    disp('enviado');
    valor=fscanf(s,'%s');

    disp('recibido');
    disp(valor)
    p=strsplit(valor,':');
    l1=str2double(p(1,1));
    l2=str2double(p(1,2));
    l3=str2double(p(1,3));
    v1(c,1)=l1;
    v2(c,1)=l2;
    v3(c,1)=l3;



v1=v1*5/4095;
v2=v2*5/4095;
v3=v3*5/4095;

    voltaje(c,1)=v1(c,1);
    voltaje(c,2)=v2(c,1);
    voltaje(c,3)=v3(c,1);
    axis([0 1000 0 5]);
    plot(voltaje);
    drawnow;
end
fprintf(s,'%d',0);
fclose(s);
delete(s);
clear s;


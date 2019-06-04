# Stepper Motor Library

[![Version](https://img.shields.io/github/release/cesar-a-benitez/StepperMotor.svg?style=plastic)](https://github.com/cesar-a-benitez/StepperMotor/releases/tag/v1.2)
[![LatestReleaseDate](https://img.shields.io/github/release-date/cesar-a-benitez/StepperMotor.svg?style=plastic)]((https://github.com/cesar-a-benitez/StepperMotor/releases/tag/v1.2))
![Issues](https://img.shields.io/github/issues/cesar-a-benitez/StepperMotor.svg?style=plastic)
[![License](https://img.shields.io/github/license/desktop/desktop.svg?style=plastic)](https://github.com/desktop/desktop/blob/development/LICENSE)
![Repo Size](https://img.shields.io/github/repo-size/cesar-a-benitez/StepperMotor.svg?style=plastic)
[![Contact](https://img.shields.io/badge/Contact-E--mail-informational.svg?style=plastic)](mailto:cesar.augusto@ecomp.ufsm.br?subject=Contact%20Stepper%20Motor%20Library)
![Follow](https://img.shields.io/github/followers/cesar-a-benitez.svg?label=Follow&style=social)

Library created by: Cesar Augusto B. Barbosa  
Latin American Center for Open Technologies (CELTAB)    
Itaipu Technological Park (PTI)

***
## About Library (Sobre a Biblioteca):
  (en)
    This Library was designed to control the Cubetto


  (pt-br)
    Esta Biblioteca foi desenvolvida para ccontrolar o Cubetto

***
## Functions List (Lista de Funções):


   Function <br> Função | Description <br> Descrição
   ----|----
   StepperMotor(int in1, int in2, int in3, int in4) | Constructor to use the motors separately <br> Construtor para usar os motores separadamente
   StepperMotor(int in1, int in2, int in3, int in4, int in5, int in6, int in7, int in8) | Constructor to use both the motors togheter <br>  Construtor para usar ambos os motores juntos
   init()                               | Configure the motors <br> Configura os motores
   setDelay(int delayTime)              | Set the step delay <br> Define o delay de cada passo
   getDelay()                           | Get the delay <br> Retorna valor do delay
   setDefaultDelay()                    | Set the default delay <br> Define valor padrão do delay
   setWheelDiameter(float diameter)     | Set the wheel diameter <br> Define diametro da roda
   setDefaultWheelDiameter()            | Set the default wheel diameter <br> Define valor padrão de diametro da roda
   getWheelDiameter()                   | Get the wheel diameter <br> Retorna o valor de diametro da roda
   setSqrDistance(float distance)       | Set the distance to walk <br> Define a distância para andar
   getSqrDistance()                     | Get the distance to walk <br> Retorna o valor da distância para andar
   setDefaultSqrDistance()              | Set the default distance to walk <br> Define o valor padrão de distância para andar
   setDistanceBtwWheels(float distance) | Set the distance between wheels <br> Define o valor da distância entre as rodas
   setDefaultDistanceBtwWheels()        | Set the default distance between wheels <br> Define o valor padrão da distância entre as rodas
   getDistanceBtwWheels()               | Get the distance between wheels <br> Retorna o valor da distância entre as rodas
   stepForward()                        | One step forward <br> Um passo para frente
   stepForwardMotor1()                  | Motor 1: one step forward <br> Um passo para frente
   stepForwardMotor2()                  | Motor 2: one step forward <br> Um passo para frente
   stepBackward()                       | One step backward <br> Um passo para trás
   stepBackwardMotor1()                 | Motor 1: one step backward <br> Um passo para trás
   stepBackwardMotor2()                 | Motor 2: one step backward <br> Um passo para trás
   turnLeft()                           | Steps to turn Left <br> Passos para virar a esquerda
   turnRight()                          | Steps to turn Right <br> Passos para virar a direita
   stepDegrees(float degrees)           | Turn motors in the desired angle <br> Gire os motores no angulo desejado
   stepDegreesMotor1(float degrees)     | Turn motor 1 in the desired angle <br> Gire o motor 1 no angulo desejado
   stepDegreesMotor2(float degrees)     | Turn motor 2 in the desired angle <br> Gire o motor 2 no angulo desejado
   turnDegrees(float degrees)           | Turn motor in the desired angle <br> Gire o motor no angulo desejado
   forwardDistance(float distance)      | Forward at a desired distance (negative value for Backwards) <br> Anda para frente em uma distância desejada (valor negativo para andar para trás)
   forwardDefault()                     | Forward default distance <br>  Anda para frente a distância padrão
   backwardDefault()                    | Backward default distance <br> Anda para trás a distância padrão
   turnRightDefault()                   | Turns 90 degrees right <br> Vira 90 graus para direita
   turnLeftDefault()                    | Turns 90 degrees left <br> Vira 90 graus para esquerda

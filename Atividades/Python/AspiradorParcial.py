import random

class Cena:

    def __init__(self):
        estados = ["Limpa", "Suja"]
        self.salaA = random.choice(estados)
        self.salaB = random.choice(estados)

class Agente:
    def __init__(self):
        salas = ["A", "B"]
        self.salaAtual = random.choice(salas)
        self.desempenho = 0
    
    def noOp(self):
        print("Parado")
    
    def Scan(self, Cena):
        if self.salaAtual == "A":
            if(Cena.salaA == "Suja"):
                self.desempenho += 10
                Cena.salaA = "Limpa"
                print("Sala A Limpa!")
            else:
                print("Agente se movendo para Direita A -> B")
                self.Direita()

        if self.salaAtual == "B":
            if(Cena.salaB == "Suja"):
                Cena.salaB = "Limpa"
                print("Sala B Limpa!")
                self.desempenho += 10
            else:
                print("Agente se movendo para Esquerda A <- B")
                self.Esquerda()

    def Direita(self):
        if self.salaAtual == "A":
            self.salaAtual = "B"

    def Esquerda(self):
        if self.salaAtual == "B" :
            self.salaAtual = "A"
    


cenario = Cena()
print(cenario.salaA)
print(cenario.salaB)

agente = Agente()
print(agente.salaAtual)

for i in range(1, 1000):
    agente.Scan(cenario)
    poeira = random.randint(0, 4)
    if poeira == 0:
        cenario.salaA = "Suja"

    if poeira == 2:
        cenario.salaB = "Suja"

print(agente.desempenho)

    
from faker import Faker
import random

# Inicializar Faker para generar nombres y apellidos en español
fake = Faker('es_ES')  # Para generar nombres y apellidos en español

# Lista de salarios y roles
salarios_roles = [
    (5000, "Gerente"),
    (4000, "Ingeniera"),
    (4500, "Supervisor"),
    (3500, "Asistente")
]

# Función para generar un usuario con nombre y apellido simples (sin compuestos)
def generar_usuario():
    # Generar un nombre simple
    while True:
        nombre = fake.first_name()  # Genera un nombre aleatorio
        if ' ' not in nombre:  # Asegurarse de que no sea un nombre compuesto
            break
    
    # Generar un apellido simple
    while True:
        apellido = fake.last_name()  # Genera un apellido aleatorio
        if ' ' not in apellido:  # Asegurarse de que no sea un apellido compuesto
            break
    
    # Seleccionar un salario y rol aleatorio y añadir decimales al salario
    salario, rol = random.choice(salarios_roles)
    salario = round(random.uniform(salario - 500, salario), 2)  # Genera salario con decimales
    return f"{nombre} {apellido} {salario} {rol}"

# Generar 1000 usuarios
usuarios = [generar_usuario() for _ in range(1000)]

# Guardar los usuarios en un archivo o imprimir en la consola
with open("usuarios.txt", "w") as archivo:
    for usuario in usuarios:
        archivo.write(usuario + "\n")

# También puedes imprimir los primeros 10 usuarios como ejemplo
for usuario in usuarios[:10]:
    print(usuario)

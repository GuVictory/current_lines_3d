"""
    Функция берет файл сетки и создает отдельный файл,
    который хранит в себе данные об узлах в формате:
        id x y z field_x field_y field_z
"""
def create_nodes_file():
    result_nodes_lines = []

    with open("data_preparing/source_files/mesh.dat", "r") as source_f:
        line = source_f.readline().split(' ')
        real_node_counter = int(line[1])

        for ind in range(real_node_counter):
            node = source_f.readline().split(' ')
            x = float(node[6])
            y = float(node[7])
            z = float(node[8])
            result_nodes_lines.append(f'{ind} {x} {y} {z} ')

        with open("data_preparing/source_files/dump.dmp", "r") as source_field_f:
            for ind in range(len(result_nodes_lines)):
                field = source_field_f.readline().split('\t')
                x = float(field[0])
                y = float(field[1])
                z = float(field[2])
                result_nodes_lines[ind] += f'{x} {y} {z}\n'

    with open("data_preparing/prepared_files/nodes.dat", "w") as prepared_f:
        prepared_f.writelines(result_nodes_lines)



"""
    Функция берет файл сетки и создает отдельный файл,
    который хранит в себе данные об гексаэдрах в формате:
        id node1 node2 node3 node4 node5 node6 node7 node8
"""
def create_hexahedrons_file():
    hexahedrons_result = []

    with open("data_preparing/source_files/mesh.dat", "r") as source_f:

        # Сначала в файле идут узлы, считываем и пропускаем
        line = source_f.readline().split(' ')
        counter = int(line[0])
        for ind in range(counter):
            source_f.readline()

        # Потом в файле идет еще что-то, считываем и пропускаем
        line = source_f.readline().split(' ')
        counter = int(line[1])
        for ind in range(counter):
            source_f.readline()

        # Потом в файле идет еще что-то, считываем и пропускаем
        line = source_f.readline().split(' ')
        counter = int(line[1])
        for ind in range(counter):
            source_f.readline()

        # Потом уже идут нужные нам гексаэдры
        line = source_f.readline().split(' ')
        counter = int(line[0])
        for ind in range(counter):
            hexahedron = source_f.readline().split(' ')
            node1 = int(hexahedron[0])
            node2 = int(hexahedron[1])
            node3 = int(hexahedron[2])
            node4 = int(hexahedron[3])
            node5 = int(hexahedron[4])
            node6 = int(hexahedron[5])
            node7 = int(hexahedron[6])
            node8 = int(hexahedron[7])
            hexahedrons_result.append(f'{ind} {node1} {node2} {node3} {node4} {node5} {node6} {node7} {node8}\n')

    with open("data_preparing/prepared_files/hexahedrons.dat", "w") as prepared_f:
        prepared_f.writelines(hexahedrons_result)



def create_files():
    create_nodes_file()
    create_hexahedrons_file()


if __name__ == '__main__':
    create_files()

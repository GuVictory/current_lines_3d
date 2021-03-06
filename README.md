# ВИЗУАЛИЗАЦИЯ ВЕКТОРНЫХ ПОЛЕЙ С ПОМОЩЬЮ ЛИНИЙ ТОКА


Постановка задачи:
---
- Разработать метод визуализации трехмерного векторного поля с помощью линий тока.
- Для количественной оценки величины модуля вектора использовать цветовое кодирование.
- Получить анимацию изменения линий тока в разные моменты времени.
- Выполнить визуализацию с помощью трубок тока.

---
Основные сущности для работы:
---

* **Point** - хранит координаты x, y, z
* **Node** - узел, у которого есть координаты, значение векторного поля и id (если id не задается явно, то id = 0)
* **Line** - линия, состоящая из двух узлов, в дальнейшем необходима для вычисления 
точки пересечениния сканирующей линии и грани ячейки.
* **Field** - векторное поле, наследуется от **Point** и предоставляет возможность получения
модуля силы векторного поля в точке, а => и нормированного значения векторного поля в данной точке
* **Plane** - часть плоскости, ограниченная 4 узлами
* **Cell**  - Ячейка, состоящая из 8 узлов (в начальном варианте работы рассмотрим прямоугольные ячейки)
* **Mesh** - хранит в себе сетку из узлов и ячеек


---
Структура файлов сетки для загрузки:
---

* Файл с узлами хранит данные в формате:  
```
node_counts  
id x y z field_x field_y field_z  
...  
id x y z field_x field_y field_z
```

* Файл с гексаэдарами хранит данные в формате:  
```
hexahedron_counts  
id node1 node2 node3 node4 node5 node6 node7 node8
...  
id node1 node2 node3 node4 node5 node6 node7 node8
```

---
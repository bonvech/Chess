///< @file Queen.h

/**
 @author Roma, Timofey

 Queen - ����� ������ ��������;

 ������� ������ BaseFigure.
*/
class Queen: public BaseFigure{
 public:
    /// �����������
    Queen(int type0, int x_cell0, int y_cell0, COLORREF main_color0, COLORREF side_color0) : BaseFigure(type0, x_cell0, y_cell0, main_color0, side_color0){}
    virtual void draw(int x, int y, int r) override;                                           // ���������
    virtual void count_move_ability_cells(vector<BaseFigure*> figures) override;               // ������� ����������� �����
    virtual void change() override{}
};
/**
 ������� ��������� ��������;
 \param x  - ���������� �������� �� ��� x;
 \param y  - ���������� �������� �� ��� y;
 \param r  - ������ ��������.
 */
void Queen::draw(int x, int y, int r){
    txSetColor(side_color ,2);
    txSetFillColor (main_color);

    POINT head[24] = {{((5)*r)+x, ((0)*r)+y}, {((6)*r)+x, ((0)*r)+y}, {((6)*r)+x, ((1)*r)+y},
                      {((7)*r)+x, ((1)*r)+y}, {((7)*r)+x, ((2)*r)+y}, {((6)*r)+x, ((2)*r)+y},
                      {((6)*r)+x, ((4)*r)+y}, {((8)*r)+x, ((4)*r)+y}, {((6)*r)+x, ((5)*r)+y},
                      {((6)*r)+x, ((6)*r)+y}, {((7)*r)+x, ((6)*r)+y}, {((7)*r)+x, ((8)*r)+y},
                      {((6)*r)+x, ((10)*r)+y}, {((5)*r)+x, ((10)*r)+y}, {((4)*r)+x, ((8)*r)+y},
                      {((4)*r)+x, ((6)*r)+y}, {((5)*r)+x, ((6)*r)+y}, {((5)*r)+x, ((5)*r)+y},
                      {((3)*r)+x, ((4)*r)+y}, {((5)*r)+x, ((4)*r)+y}, {((5)*r)+x, ((2)*r)+y},
                      {((4)*r)+x, ((2)*r)+y}, {((4)*r)+x, ((1)*r)+y}, {((5)*r)+x, ((1)*r)+y}}; // "������", �������� � ����������� �� ������
    txPolygon (head, 24);

    POINT body[4] = {{(5*r)+x, (10*r)+y}, {(6*r)+x, (10*r)+y}, {(8*r)+x, (20*r)+y}, {(3*r)+x, (20*r)+y}}; // ������������ ����
    txPolygon (body, 4);

    POINT stand1[4] = {{(2*r)+x, (20*r)+y}, {(9*r)+x, (20*r)+y}, {(9*r)+x, (21*r)+y}, {(2*r)+x, (21*r)+y}}; // ������ ��������� ��� ����, � � ����� ������ ���
    txPolygon (stand1, 4);

    POINT stand2[4] = {{(1*r)+x, (21*r)+y}, {(10*r)+x, (21*r)+y}, {(10*r)+x, (22*r)+y}, {(1*r)+x, (22*r)+y}}; // ������ ��������� ��� �������(�����,����,����) � ������
    txPolygon (stand2, 4);

    POINT stand3[4] = {{(0*r)+x, (22*r)+y}, {(11*r)+x, (22*r)+y}, {(11*r)+x, (23*r)+y}, {(0*r)+x, (23*r)+y}};// ������ ��������� ��� ������(������, �������)
    txPolygon (stand3, 4);
}
/**
 ������� �������� ����������� ����;

 \param figures  - ������ �����.

 �������� ����� � ��� � ����� ������� �� ����� ����������� ������;

*/
void Queen :: count_move_ability_cells(vector<BaseFigure*> figures) {
    move_ability_cells.clear();
    bool out = false;
    for(int i = 1; (y_cell - i >= 0) && (x_cell + i < 8); i++) {   // ����� �����
        int* cell = new int[2];
        cell[0] = y_cell - i;
        cell[1] = x_cell + i;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell - i)) && (figura->get_x_cell() == (x_cell + i))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }

    out = false;
    for(int i = 1; (y_cell - i >= 0) && (x_cell - i >= 0); i++) {  // ����� ����
        int* cell = new int[2];
        cell[0] = y_cell - i;
        cell[1] = x_cell - i;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell - i)) && (figura->get_x_cell() == (x_cell - i))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }
    out = false;
    for(int i = 1; (y_cell + i < 8) && (x_cell + i < 8); i++) {    // ����� �����
        int* cell = new int[2];
        cell[0] = y_cell + i;
        cell[1] = x_cell + i;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell + i)) && (figura->get_x_cell() == (x_cell + i))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }
    out = false;
    for(int i = 1; (y_cell + i < 8) && (x_cell - i >= 0); i++) {   // ���� �����
        int* cell = new int[2];
        cell[0] = y_cell + i;
        cell[1] = x_cell - i;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((figura->get_y_cell() == (y_cell + i)) && (figura->get_x_cell() == (x_cell - i))) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }

    out = false;
    for(int i = y_cell-1; i >= 0; i--) {            // �����
        int* cell = new int[2];
        cell[0] = i;
        cell[1] = x_cell;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((i == figura->get_y_cell()) && (x_cell == figura->get_x_cell())) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }

    out = false;
    for(int i = y_cell+1; i <= 7; i++) {             // ����
        int* cell = new int[2];
        cell[0] = i;
        cell[1] = x_cell;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((i == figura->get_y_cell()) && (x_cell == figura->get_x_cell())) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }

    out = false;
    for(int j = x_cell-1; j >= 0; j--) {             // �����
        int* cell = new int[2];
        cell[0] = y_cell;
        cell[1] = j;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((y_cell == figura->get_y_cell()) && (j == figura->get_x_cell())) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }

    out = false;
    for(int j = x_cell+1; j <= 7; j++) {             // ������
        int* cell = new int[2];
        cell[0] = y_cell;
        cell[1] = j;

        move_ability_cells.push_back(cell);

        for(auto figura : figures) {
            if((y_cell == figura->get_y_cell()) && (j == figura->get_x_cell())) {
                   if(type == figura->get_type()){
                        move_ability_cells.pop_back();
                   }
                   out = true;
                   break;
            }
        }
        if(out){
            break;
        }
    }
}

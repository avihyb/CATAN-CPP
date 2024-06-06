#include "board.hpp"
#include "tile.hpp"
#include "vertex.hpp"
#include "edge.hpp"

namespace ariel {
    Board::Board() {
        initializeBoard();
    }
    
    void Board::initializeBoard() {
        initializeVerticies();

        Vertex v1(1);
        Vertex v2(2);
        Vertex v3(3);
        Vertex v4(4);
        Vertex v5(5);
        Vertex v6(6);
        Vertex v7(7);
        Vertex v8(8);
        Vertex v9(9);
        Vertex v10(10);
        Vertex v11(11);
        Vertex v12(12);
        Vertex v13(13);
        Vertex v14(14);
        Vertex v15(15);
        Vertex v16(16);
        Vertex v17(17);
        Vertex v18(18);
        Vertex v19(19);
        Vertex v20(20);
        Vertex v21(21);
        Vertex v22(22);
        Vertex v23(23);
        Vertex v24(24);
        Vertex v25(25);
        Vertex v26(26);
        Vertex v27(27);
        Vertex v28(28);
        Vertex v29(29);
        Vertex v30(30);
        Vertex v31(31);
        Vertex v32(32);
        Vertex v33(33);
        Vertex v34(34);
        Vertex v35(35);
        Vertex v36(36);
        Vertex v37(37);
        Vertex v38(38);
        Vertex v39(39);
        Vertex v40(40);
        Vertex v41(41);
        Vertex v42(42);
        Vertex v43(43);
        Vertex v44(44);
        Vertex v45(45);
        Vertex v46(46);
        Vertex v47(47);
        Vertex v48(48);
        Vertex v49(49);
        Vertex v50(50);
        Vertex v51(51);
        Vertex v52(52);
        Vertex v53(53);
        Vertex v54(54);

        Edge e1(v1, v2);
        Edge e2(v2, v3);
        Edge e3(v3, v4);
        Edge e4(v4, v5);
        Edge e5(v5, v6);
        Edge e6(v6, v7);
        Edge e7(v7, v8);
        Edge e8(v8, v9);
        Edge e9(v9, v10);
        Edge e10(v10, v11);
        Edge e10_5(v10, v5);
        Edge e11(v11, v12);
        Edge e12(v12, v13);
        Edge e12_3(v12, v3);
        Edge e13(v13, v14);
        Edge e14_1(v14, v1);
        Edge e14(v14, v15);
        Edge e15(v15, v16);
        Edge e16(v16, v17);
        Edge e17(v17, v18);
        Edge e18_13(v18, v13);
        Edge e18(v18, v19);
        Edge e19(v19, v20);
        Edge e20_11(v20, v11);
        Edge e20(v20, v21);
        Edge e21(v21, v22);
        Edge e22_9(v22, v9);

        /*
        Board layout:
        
              <t1> <t2> <t3>
            <t4> <t5> <t6> <t7>
        <t8> <t9> <t10> <t11> <t12>
           <t13> <t14> <t15> <t16>
             <t17> <t18> <t19>

        */
        Tile t1("Mountain", 10, {v1, v2, v3, v12, v13, v14}, {e1, e2, e3, e4, e5, e6});
        Tile t2("Pasture", 2, {v3, v4, v5, v10, v11, v12}, {e3, e4, e5, e10_5, e10, e11});
        Tile t3("Forest", 9, {v5, v6, v7, v8, v9, v10}, {e5, e6, e7, e8, e9, e10_5});
        Tile t4("Fields", 12, {v13, v14, v15, v16, v17, v18}, {e13, e14, e14_1, e15, e16, e17, e18_13});
        Tile t5("Hills", 6, {v18, v19, v20, v13, v12, v11}, {e18, e19, e18_13, e11, e12});
        Tile t6("Pasture", 4, {v20, v21, v22, v9, v10, v11}, {e20, e21, e22_9, e9, e10, e20_11});

    }

    void Board::initializeVerticies() {

        

    }
    
    
}
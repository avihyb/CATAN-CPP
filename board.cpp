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
        Vertex v55(55);

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
        Edge e22(v22, v23);
        Edge e23(v23, v24);
        Edge e24(v24, v25);
        Edge e25_8(v25, v8);
        Edge e37(v37, v38);
        Edge e36(v36, v37);
        Edge e35(v35, v36);
        Edge e17_35(v17, v35);
        Edge e34(v34, v35);
        Edge e33(v33, v34);
        Edge e19_33(v19, v33);
        Edge e32(v32, v33);
        Edge e31(v31, v32);
        Edge e21_31(v21, v31);
        Edge e30(v30, v31);
        Edge e23_29(v23, v29);
        Edge e21_31(v21, v31);
        Edge e29(v29, v30);
        Edge e28(v28, v29);
        Edge e27(v27, v28);
        Edge e24_26(v24, v26);
        Edge e26(v26, v27);
        Edge e36_39(v36, v39);
        Edge e34_41(v34, v41);
        Edge e40(v40, v41);
        Edge e39(v39, v40);
        Edge e34_41(v34, v41);
        Edge e41(v41, v42);
        Edge e42(v42, v43);
        Edge e32_43(v32, v43);
        Edge e43(v43, v44);
        Edge e44(v44, v45);
        Edge e30_45(v30, v45);
        Edge e45(v45, v46);
        Edge e46(v46, v47);
        Edge e47(v47, v48);
        Edge e28(v28, v48);
        Edge e40_55(v40, v55);
        Edge e54(v54, v55);
        Edge e53(v53, v54);
        Edge e42_53(v42, v53);
        Edge e52(v52, v53);
        Edge e51(v51, v52);
        Edge e44_51(v44, v51);
        Edge e49(v49, v50);
        Edge e46_49(v46, v49);
        Edge e50(v50, v51);
        


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
        Tile t7("Hills", 10, {v22, v23, v24, v25, v9, v8}, {e22_9, e22, e23, e24, e25_8});
        Tile t8("Fields", 9, {v38, v16, v17, v35, v36, v37}, {e16, e37, e36, e35, e17_35});
        Tile t9("Forest", 9, {v35, v34, v33, v19, v17, v18}, {e17_35, e34, e33, e19_33, e18, e17});
        Tile t10("Desert", 0, {v33, v32, v31, v21, v20, v19}, {e19_33, e32, e31, e21_31, e20, e19}); // SHODED
        Tile t11("Forest", 3, {v31, v30, v29, v23, v22, v21}, {e21_31, e30, e23_29, e21, e22, e29});
        Tile t12("Mountain", 8, {v29, v28, v27, v26, v24, v23}, {e23_29, e28, e27, e24_26, e23, e26});
        Tile t13("Forest", 8, {v39, v36, v35, v34, v41, v40}, {e36_39, e35, e34, e34_41, e40, e39});
        Tile t14("Mountain", 3, {v41, v42, v43, v32, v33, v34},{e34_41, e41, e42, e32_43, e32, e33});
        Tile t15("Fields", 4, {v43, v44, v45, v30, v31, v32}, {e32_43, e43, e44, e30_45, e30, e31});
        Tile t16("Pasture", 5, {v45, v46, v47, v48, v28, v30}, {e30_45, e45, e46, e47, e28, e29});
        Tile t17("Hills", 5, {v55, v54, v53, v42, v41, v40}, {e40_55, e54, e53, e42_53, e40, e41});
        Tile t18("Fields", 6, {v53, v52, v51, v42, v43, v44}, {e42_53, e52, e51, e44_51, e42, e43});
        Tile t19("Pasture", 11, {v51, v50, v49, v46, v45, v44}, {e44_51, e49, e46_49, e45, e44, e50});
    }

    void Board::initializeVerticies() {

        

    }
    
    
}
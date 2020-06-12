#ifndef CHARACTOR
#define CHARACTOR

#include<vector>
namespace PCR {

    class Charactor {
        public:
            float   max_hp; 
            float const  max_tp;

            unsigned int const rank;
            // unsigned int const star;
            // unsigned int const level;

            /*
            float cur_hp; 
            float hp_rcv;  //   hp 自动回复
            float hp_stl;  //   hp 偷取

            float cur_tp;
            float tp_upp;  //   tp 上升
            float tp_lgt;  //   tp 消耗减轻
            float tp_rcv;  //   tp 自动回复 

            float atk_phy; //   atk 物理

            float atk_hit; //   atk 命中

            float atk_mag; //   atk 魔法

            float def_phy; //   def 物理
            float def_mag; //   def 魔法
            float dooodge; //   闪避 < 1

            float crt_phy; //   暴击 物理
            float crt_mag; //   暴击 魔法

            float rcv_upp; //   回复 上升
            float atk_rag; //   atk 距离
        */
            explicit Charactor(float h, float t)
                : max_hp { h }, max_tp { t }, rank { 7 } {/*绝不要在构造函数中使用virtual函数*/ }
            virtual void skill(std::vector<Charactor*>&) = 0;
            virtual ~Charactor() = default;
    };

} // end namespace PCR
#endif

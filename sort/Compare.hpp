//
//  Compare.hpp
//  sort
//
//  Created by Wojiaxiaoguan on 2017/5/9.
//  Copyright © 2017年 Wojiaxiaoguan. All rights reserved.
//

#ifndef Compare_hpp
#define Compare_hpp

class Compare {
public:
    static bool lt(int x,int y){return x < y;}
    static bool eq(int x,int y){return x == y;}
    static bool gt(int x,int y){return x > y;}
};

#endif /* Compare_hpp */

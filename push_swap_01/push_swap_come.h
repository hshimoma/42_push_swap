#ifndef PUSH_SWAP_COME_H
#define PUH_SWAP_COME_H

#include <stdio.h> //sa_sb_ss.c,pa_pb.c,ra_rb_rr.c,rra_rrb_rrr.c
#include <stdlib.h> //sa_sb_ss,c,pa_pb.c.ra_rb_rr.c,rra_rrb_rrr.c

typedef struct s_node //ノードの構造体（スタックの各要素）,pa_pb.c,ra_rb_rr.c,rra_rrb_rrr.c
{
    int value; //ノードの値
    struct s_node *next; //次のノードへのポインタ
} t_node;

typedef struct s_stack //スタック構造体（スタックのトップを管理） pa_pb.c,ra_rb_rr.c,rra_rrb_rrr.c
{
    t_node *top; //スタックのトップのノードを示すポインタ
} t_stack;


t_node *node_clear(t_stack *stack); //pa_pb.c,ra_rb_rr.c

#endif
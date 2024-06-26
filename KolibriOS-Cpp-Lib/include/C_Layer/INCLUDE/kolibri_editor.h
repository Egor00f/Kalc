

#ifndef KOLIBRI_EDITOR_H
#define KOLIBRI_EDITOR_H

#include <kos32sys.h>

// (êîëè÷åñòâî ñèìâîëîâ â íîâîì äîêóìåíòå + 2)
#define TE_MAXCHARS 100002
// ìàêñèìàëüíûé ðàçìåð ôàéëà ñèíòàêñèñà
#define TE_MAX_SYNTAX_FILESIZE 410000
// buffer for copy|paste
#define TE_BUF_SIZE 4096
typedef void (*editor_callback)(void);

struct __attribute__((__packed__)) editor_symbol
{
    uint8_t c;     //  +0 ñèìâîë
    uint8_t col;   //  +1 öâåò
    uint32_t prev; //  +2 èíäåêñ ïðåäûäóùåãî
    uint32_t next; //  +6 óêàçàòåëè (èíäåêñ ñëåäóþùåãî)
    uint32_t tc;   //  +10 âðåì. ñîçäàíèÿ
    uint32_t td;   // +14 âðåì. óäàëåíèÿ
};

/// ñòðóêòóðà òåêñòîâîãî ðåäàêòîðà
typedef struct __attribute__((__packed__))
{
    uint32_t x_pos;     // 0
    uint32_t y_pos;     // 50
    uint32_t width;     // 440
    uint32_t hight;     // 150
    uint32_t w_pane;    // 30 øèðèíà ïàíåëè â îêíå, width of left pane with line numbers
    uint32_t h_pane;    // 25 âûñîòà ïàíåëè â îêíå, hight of top pane with Rows, Cols Undo info
    uint32_t width_sym; // 9 øèðèíà ñèìâîëà (çíàêîìåñòà) â îêíå
    uint32_t hight_sym; // 16 âûñîòà ñèìâîëà (çíàêîìåñòà) â îêíå
    uint8_t drag_m;     // âûäåëåíèå îò ìûøè
    uint8_t drag_k;     // âûäåëåíèå îò êëàâèàòóðû
    uint32_t sel_x0;    // ñòðóêòóðà âûäåëåíèÿ
    uint32_t sel_y0;
    uint32_t sel_x1;
    uint32_t sel_y1;
    uint32_t seln_x0; // äîïîëíèòåëüíàÿ ñòðóêòóðà âûäåëåíèÿ
    uint32_t seln_y0;
    uint32_t seln_x1;
    uint32_t seln_y1;
    struct editor_symbol *tex;              // text memory pointer
    struct editor_symbol *tex_1;            // óêàçàòåëü çà ïîñëåäíèì ñóùåñòâóþùèì ñèìâîëîì (êîíåö ôàéëà)
    struct editor_symbol *tex_end;          // text end memory pointer (óêàçàòåëü çà êîíöîì âûäåëåííîãî áóôåðà äëÿ òåêñòà)
    uint32_t cur_x;                         // êîîðäèíàòà x êóðñîðà
    uint32_t cur_y;                         // êîîðäèíàòà y êóðñîðà
    uint32_t max_chars;                     // TE_MAXCHARS ;+86 ìàêñèìàëüíîå ÷èñëî ñèìâîëîâ â îäíîì äîêóìåíòå
    uint32_t count_colors_text;             // 1 ;+90 êîëè÷åñòâî öâåòîâ òåêñòà
    uint32_t count_key_words;               //+94 êîëëè÷åñòâî êëþ÷åâûõ ñëîâ
    color_t color_cursor;                   // 0x808080 ;+98 öâåò êóðñîðà
    color_t color_wnd_capt;                 // 0x80 ;+102 öâåò ïîëåé âîêðóã îêíà
    color_t color_wnd_work;                 // 0x0 ;+106 öâåò ôîíà îêíà
    color_t color_wnd_bord;                 // 0xd0d0d0 ;+110 öâåò òåêñòà íà ïîëÿõ
    color_t color_select;                   // 0x208080 ;+114 öâåò âûäåëåíèÿ
    color_t color_cur_text;                 // 0xff0000 ;+118 öâåò ñèìâîëà ïîä êóðñîðîì
    color_t color_wnd_text;                 // 0xffff00 ;+122 öâåò òåêñòà â îêíå
    char *syntax_file;                      // óêàçàòåëü íà íà÷àëî ôàéëà ñèíòàêñèñà
    uint32_t syntax_file_size;              // TE_MAX_SYNTAX_FILESIZE ;+130 ìàêñèìàëüíûé ðàçìåð ôàéëà ñèíòàêñèñà
    void *text_colors;                      // óêàçàòåëü íà ìàññèâ öâåòîâ òåêñòà
    char *help_text_f1;                     // óêàçàòåëü íà òåêñò ñïðàâêè (ïî íàæàòèè F1)
    int help_id;                            // -1 ;+142 èäåíòèôèêàòîð äëÿ ñïðàâêè
    void *key_words_data;                   // óêàçàòåëü íà ñòðóêòóðû êëþ÷åâûõ ñëîâ TexColViv
    uint32_t tim_ch;                        // êîëè÷åñòâî èçìåíåíèé â ôàéëå
    uint32_t tim_undo;                      // êîëè÷åñòâî îòìåíåííûõ äåéñòâèé
    uint32_t tim_ls;                        // âðåìÿ ïîñëåäíåãî ñîõðàíåíèÿ
    uint32_t tim_co;                        // âðåìÿ ïîñëåäíåé öâåòîâîé ðàçìåòêè
    void *el_focus;                         // óêàçàòåëü íà ïåðåìåííóþ ýëåìåíòà â ôîêóñå pointer to pointer**
    uint8_t err_save;                       // îøèáêà ñîõðàíåíèÿ ôàéëà
    uint8_t panel_id;                       // íîìåð îòêðûòîé ïàíåëè
    uint8_t key_new;                        // ñèìâîë, êîòîðûé áóäåò äîáàâëÿòñÿ ñ êëàâèàòóðû
    uint8_t symbol_new_line;                // ascii 20 ñèìâîë çàâåðøåíèÿ ñòðîêè
    scrollbar *scr_w;                       // âåðòèêàëüíûé ñêðîëëèíã != NULL
    scrollbar *scr_h;                       // ãîðèçîíòàëüíûé ñêðîëëèíã != NULL
    char *arr_key_pos;                      // óêàçàòåëü íà ìàññèâ ïîçèöèé êëþ÷åâûõ ñëîâ
    char *buffer;                           // óêàçàòåëü íà áóôåð êîïèðîâàíèÿ/âñòàâêè != NULL, also size
    char *buffer_find;                      // óêàçàòåëü íà áóôåð äëÿ ïîèñêà (sized 302)
    uint8_t cur_ins;                        // 1 ðåæèì ðàáîòû êóðñîðà (îáû÷íûé èëè çàìåíà)
    uint8_t mode_color;                     // 1 ðåæèì âûäåëåíèÿ ñëîâ öâåòîì (0-âûêë. 1-âêë.)
    uint8_t mode_invis;                     // 0 ðåæèì ïîêàçà íåïå÷àòàåìûõ ñèìâîëîâ
    uint8_t gp_opt;                         // 0 îïöèè âîçâðàùàåìûå ôóíêöèåé ted_get_pos_by_cursor
    editor_callback fun_on_key_ctrl_all;    // óêàçàòåëü íà ôóíêöèþ âûçûâàåìóþ ïðè íàæàòèè Ctrl+N,O,S,F,G,H, can be NULL
    uint32_t reserved_1;                    // ...
    uint32_t reserved_2;                    // ...
    uint32_t reserved_3;                    // ...
    uint32_t buffer_size;                   // BUF_SIZE ðàçìåð áóôåðà êîïèðîâàíèÿ/âñòàâêè
    editor_callback fun_find_err;           // óêàçàòåëü íà ôóíêöèþ âûçûâàåìóþ åñëè ïîèñê çàêîí÷èëñÿ íåóäà÷íî
    editor_callback fun_init_synt_err;      // unused óêàçàòåëü íà ôóíêöèþ âûçûâàåìóþ ïðè îøèáî÷íîì îòêðûòèè ôàéëà ñèíòàêñèñà
    editor_callback fun_draw_panel_buttons; // óêàçàòåëü íà ôóíêöèþ ðèñîâàíèÿ ïàíåëè ñ êíîïêàìè
    editor_callback fun_draw_panels;        // óêàçàòåëü íà ôóíêöèþ ðèñîâàíèÿ ïàíåëè ïîèñêà|çàìåíû|ïåðåõîäà|ñèíòàêñèñà
    uint32_t reserved_4;                    // ...
    editor_callback fun_save_err;           // óêàçàòåëü íà ôóíêöèþ âûçûâàåìóþ åñëè ñîõðàíåíèå ôàéëà çàêîí÷èëîñü íåóäà÷íî
    uint32_t increase_size;                 // 200 ÷èñëî ñèìâîëîâ íà êîòîðûå áóäåò óâå÷èâàòüñÿ ïàìÿòü ïðè íåõâàòêå
    void *ptr_free_symb;                    // èñïîëüçóåòñÿ âíóòðè ýëåìåíòà äëÿ óñêîðåíèÿ âñòàâêè òåêñòà
    uint32_t font_size;                     // ;+250 ìíîæèòåëü äëÿ ðàçìåðà øðèôòà // binary OR mask for ECX SysFn4
} editor;

struct __attribute__((__packed__)) editor_color_item
{
    char word[40];      // ñëîâî äëÿ ïîäñâåòêè
    uint32_t f1_offset; // ñìåùåíèå â òàáëèöå F1 ïîäñêàçîê
    uint8_t flags;      // ôëàãè èñïîëüçóåìûå ïðè âûäåëåíèè
    uint8_t endc;       // ñèìâîë êîíöà âûäåëåíèÿ (èñïîëüçóåòñÿ ïðè flags&4)
    uint8_t escc;       // ýêðàíèðóþùèé ñèìâîë (èñïîëüçóåòñÿ ïðè flags&4)  ascii(34) ïðèìåðû ýêðàíèðîâàíèÿ \r \n \t
    uint8_t color;      // öâåò ïî òàáëèöå öâåòîâ
};

struct editor_syntax_file
{
    uint32_t count_colors_text; // êîë-âî öâåòîâ òåêñòà dd (text-color_wnd_text)/4
    uint32_t count_key_words;   // êîë-âî êëþ÷åâûõ ñëîâ dd (f1-text)/48
    color_t color_cursor;       // dd 0xf1fcd0
    color_t color_wnd_capt;     // dd 0x080808
    color_t color_wnd_work;     // dd 0x1C1C1C
    color_t color_wnd_bord;     // dd 0xc0c0c0
    color_t color_select;       // dd 0x3E3D32
    color_t color_cur_text;     // dd 0x808080
    color_t color_wnd_text[];   // òàáëèöà öâåòîâ ðàçìåðîì count_colors_text
    // editor_color_item[];         // òàáëèöà êëþ÷åâûõ ïîäñâå÷åííûõ ñëîâ ðàçìåðîì count_key_words
};

static struct editor_syntax_file default_syntax = {
    10,       // count_colors_text
    1,        // count_key_words dd (f1-text)/48, minimum 1
    0xf1fcd0, // color_cursor dd 0xf1fcd0
    0x080808, // color_wnd_capt dd 0x080808
    0x1C1C1C, // color_wnd_work dd 0x1C1C1C
    0xc0c0c0, // color_wnd_bord dd 0xc0c0c0
    0x3E3D32, // color_select dd 0x3E3D32
    0x808080, // color_cur_text dd 0x808080
    {0xD0D0D0, 0xffff00, 0x00ff00, 0x00ffff, 0x808080, 0xff40ff, 0x4080ff, 0xff0000, 0x8080ff, 0x00ccff}};
// next structure must follow syntax definition, at least has 1 element !!!
static struct editor_color_item word1 = {
    "siemargl", 1, 0, 0, 1 // test word colored as 1st in table
};
// next structure preferably follow syntax definition, at least has 1 element !!!
static char f1_table[] = {
    "\0"
    "First\0"
    "Last\0"};

extern void (*ted_draw)(editor *) __attribute__((__stdcall__));
extern void (*ted_init_scroll_bars)(editor *, int opt) __attribute__((__stdcall__));
/// opt bits = 1 - ìåíÿòü öâåò ñêðîëëèíãîâ, 2 - èçìåíèëèñü ðàçìåðû îêíà, 4 - èçìåíèëèñü ðàçìåðû äîêóìåíòà
extern void (*ted_init_syntax_file)(editor *) __attribute__((__stdcall__));
extern void (*ted_mouse)(editor *) __attribute__((__stdcall__));
extern void (*ted_text_add)(editor *, char *text, int textlen, int opt) __attribute__((__stdcall__));
/// add text to cursor pos
/// opt == ted_opt_ed_change_time, ted_opt_ed_move_cursor
/// ted_opt_ed_move_cursor equ 1 ;äâèãàòü êóðñîð ïîñëå äîáàâëåíèÿ òåêñòà
/// ted_opt_ed_change_time equ 2 ;äîáàâëÿòü èçìåíåíèÿ ïðè ðåäàêòèðîâàíèè òåêñòà
extern void (*ted_but_select_word)(editor *) __attribute__((__stdcall__));
/// select word under cursor
extern void (*ted_but_copy)(editor *) __attribute__((__stdcall__));
extern void (*ted_but_paste)(editor *) __attribute__((__stdcall__));

extern void (*ted_but_find)(editor *) __attribute__((__stdcall__));
extern void (*ted_but_replace)(editor *) __attribute__((__stdcall__));
/// move cursor to <ed_buffer_find>, calls ted_fun_find_err() if exist

extern void (*ted_but_sumb_upper)(editor *) __attribute__((__stdcall__));

extern void (*ted_but_sumb_lover)(editor *) __attribute__((__stdcall__));

extern void (*ted_but_convert_by_table)(editor *, char *table) __attribute__((__stdcall__));

/// return 1 if need to be saved (has changes), 0 otherwise
extern int (*ted_can_save)(editor *) __attribute__((__stdcall__));

/// all==1 - clear all memory
extern void (*ted_clear)(editor *, int all) __attribute__((__stdcall__));

extern void (*ted_delete)(editor *) __attribute__((__stdcall__));
static inline void editor_delete(editor *ed)
/// frees all memory (destroy)
{
    (*ted_delete)(ed);
    free(ed->scr_w);
    free(ed->scr_h);
    free(ed->buffer);
    free(ed->buffer_find);
}

/// allocate memory
extern void (*ted_init)(editor *) __attribute__((__stdcall__));

/// return 1 if have selection
extern int (*ted_is_select)(editor *) __attribute__((__stdcall__));

enum control_keys
{
    KM_SHIFT = 0x00010000,
    KM_CTRL = 0x00020000,
    KM_ALT = 0x00040000,
    KM_NUMLOCK = 0x00080000
};

extern void (*ted_key_asm)(editor *, char *table, int control) __attribute__((__stdcall__));
static inline __attribute__((__stdcall__)) void editor_keyboard(editor *ed, char *table, enum control_keys control, int ch)
/// control is KM_SHIFT, KM_ALT, KM_CTRL, KM_NUMLOCK,
/// ch = GET_KEY
/// table = SF_SYSTEM_GET,SSF_KEYBOARD_LAYOUT
{
    __asm__ __volatile__(
        "push %4\n\t"
        "push %3\n\t"
        "push %2\n\t"
        "call *%1 \n\t" ::"a"(ch),
        "m"(ted_key_asm), "m"(ed), "m"(table), "m"(control) :);
    /*
        __asm__ __volatile__ (
                 "nop \n\t"::"a"(ch):);
        (*ted_key_asm)(ed, table, control);
    */
}

extern void (*ted_open_file_asm)(editor *, struct fs_dirinfo *, char *fname) __attribute__((__stdcall__));
static inline int editor_openfile(editor *ed, char *fname, int *readbytes)
/// returns errcode as SysFn70
{
    int ret;
    struct fs_dirinfo di;
    __asm__ __volatile__(
        "push %%edi \n\t" :::);

    (*ted_open_file_asm)(ed, &di, fname);

    __asm__ __volatile__(
        "pop %%edi \n\t" : "=b"(*readbytes), "=a"(ret)::);
    return ret;
}

extern void (*ted_save_file_asm)(editor *, struct fs_dirinfo *, char *fname) __attribute__((__stdcall__));
static inline int editor_savefile(editor *ed, char *fname)
/// returns errcode, calls fun_save_err() if exists
{
    struct fs_dirinfo di;

    (*ted_save_file_asm)(ed, &di, fname);

    return ed->err_save;
}

extern void (*ted_but_cut)(editor *) __attribute__((__stdcall__));

extern void (*ted_but_undo)(editor *) __attribute__((__stdcall__));

extern void (*ted_but_redo)(editor *) __attribute__((__stdcall__));

extern void (*ted_but_reverse)(editor *) __attribute__((__stdcall__));

extern void (*ted_text_colored_asm)() __attribute__((__stdcall__));
static inline void editor_text_colored(editor *ed)
{
    __asm__ __volatile__(
        "call *%0 \n\t" ::"m"(ted_text_colored_asm), "D"(ed) :);
}

static inline uint32_t get_control_keys(void)
{
    uint32_t ctrl;

    __asm__ __volatile__(
        "int $0x40 \n\t"
        : "=a"(ctrl)
        : "a"(66), "b"(3));

    return ctrl;
};

static inline int get_keyboard_layout(int opt, char *buf)
/// 128 byte buffer
/// opt: 1 - normal, 2 - shifted, 3 - alted, or 9 - return language
{
    uint32_t lang;

    __asm__ __volatile__(
        "int $0x40 \n\t"
        : "=a"(lang)
        : "a"(26), "b"(2), "c"(opt), "d"(buf));

    return lang;
};

__attribute__((__stdcall__)) static void editor_key(editor *ed, oskey_t key)
// callback for gui
{
    // if(ed->el_focus != ed) return;  // need to check not to lose keyb buffer

    uint32_t control = get_control_keys();
    enum control_keys ed_ctrl = 0;
    int ly_opt = 1;
    if (control & 3)
    {
        ed_ctrl |= KM_SHIFT;
        ly_opt = 2;
    }
    if (control & 0xC)
        ed_ctrl |= KM_CTRL;
    if (control & 0x30)
    {
        ed_ctrl |= KM_ALT;
        ly_opt = 3;
    }
    if (control & 0x80)
        ed_ctrl |= KM_NUMLOCK;

    char conv_table[128];
    get_keyboard_layout(ly_opt, conv_table);

    editor_keyboard(ed, conv_table, ed_ctrl, key.val);
}

static inline void gui_add_editor(kolibri_window *wnd, editor *e)
{
    kolibri_window_add_element(wnd, KOLIBRI_EDITOR, e);
}

static inline editor *kolibri_new_editor(uint32_t x_w, uint32_t y_h, uint32_t font, uint32_t max_chars, void *editor_interlock)
/// font - 0b10SSS 8x16 size multiply (SSS+1), 0xSSS - 6x9 multiply (SSS+1)

{
    editor *ed = (editor *)calloc(1, sizeof(editor));
    ed->x_pos = x_w >> 16;
    ed->width = x_w & 0xFFFF;
    ed->y_pos = y_h >> 16;
    ed->hight = y_h & 0xFFFF;

    ed->w_pane = 30;
    ed->h_pane = 20;
    // font
    if (font == 0)
        font = 0x10; // default 16 = 8x16
    int font_multipl = (font & 7) + 1;
    ed->font_size = font << 24;
    if (font & 0x10) // 8x16
    {
        ed->width_sym = 8 * font_multipl;
        ed->hight_sym = 16 * font_multipl;
    }
    else // 6x9
    {
        ed->width_sym = 6 * font_multipl;
        ed->hight_sym = 9 * font_multipl;
    }
    // memory sizing for text & syntax
    ed->max_chars = max_chars;
    ed->increase_size = max_chars / 2;
    ed->syntax_file_size = sizeof(default_syntax);

    /* // loaded auto from syntax
        ed->color_cursor = 0x808080;
        ed->color_wnd_capt = 0x80;
        ed->color_wnd_bord = 0xd0d0d0;
        ed->color_select = 0x208080;
        ed->color_cur_text = 0xff0000;
        ed->color_wnd_text = 0xffff00;
    */
    ed->symbol_new_line = 20; // ascii(20)

    ed->scr_w = kolibri_new_scrollbar_def(X_Y(0, 16), X_Y(0, 0), 100, 30, 0); // cur_area will be inited ltr, max & pos undef
    ed->scr_h = kolibri_new_scrollbar_def(X_Y(0, 0), X_Y(0, 16), 100, 30, 0); // cur_area will be inited ltr, max & pos undef

    ed->buffer_size = TE_BUF_SIZE;
    ed->buffer = malloc(TE_BUF_SIZE);
    ed->buffer_find = malloc(TE_BUF_SIZE / 8); // where to store text to search

    ed->cur_ins = 1;    // insert mode default
    ed->mode_color = 1; // can select text
    ed->mode_invis = 1; // show nonprinted symbols

    ed->el_focus = editor_interlock;

    (*ted_init)(ed); // memory allocation, cleaning
    ed->syntax_file = (char *)&default_syntax;
    (*ted_init_syntax_file)(ed); // load colors and syntax highlight
    ed->help_text_f1 = f1_table; // override if not aligned immediately after syntax words
    ed->key_words_data = &word1;

    return ed;
}

/// return 1 if symbol is not visible (deleted or undo-ed)
static inline int editor_symbol_not_vis(editor *ed, struct editor_symbol *sym)
{
    return (sym->td && sym->td + ed->tim_undo <= ed->tim_ch) || (sym->tc > ed->tim_ch - ed->tim_undo);
}

/// returns next good symbol by index
static inline uint32_t editor_iterat_next(editor *ed, uint32_t idx)
{
    uint32_t i;
    if (ed->tim_undo)
    {
        for (i = ed->tex[idx].next; i != 0 && (ed->tex[i].c == '\n' || editor_symbol_not_vis(ed, ed->tex + i)); i = ed->tex[i].next)
            ;
    }
    else
    {
        for (i = ed->tex[idx].next; i != 0 && (ed->tex[i].c == '\n' || ed->tex[i].td); i = ed->tex[i].next)
            ;
    }
    return i;
}

// returns malloc'ed mem
static inline char *editor_get_text(editor *ed)
{
    char *buf = malloc(ed->max_chars), *pc = buf;
    if (!pc)
        return NULL;

    int i;
    //    *pc++ = ed->tex[0].c;
    for (i = ed->tex[0].next; i; i = editor_iterat_next(ed, i))
        *pc++ = ed->tex[i].c;
    *pc++ = '\0';

    return buf;
}

/*
char*  editor_get_text20(editor* ed)
{
    char    *buf = malloc(ed->max_chars), *pc = buf;
    if (!pc) return NULL;

    int  i = ed->tex[0].next, c = 0;
    for (; i > 0 && c < 30; c++, i = ed->tex[i].next) *pc++ = ed->tex[i].c;
    *pc++ = '\0';

    return buf;
}
*/
#endif // KOLIBRI_EDITOR_H

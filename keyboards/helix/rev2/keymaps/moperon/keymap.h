void render_status_slave(struct CharacterMatrix *matrix);
//void matrix_write_indicator(struct CharacterMatrix *matrix, char **indicator);
#define matrix_write_indicator(M, I) { \
  matrix_write(M, I[0]); \
  matrix_write_P(M, PSTR("\n")); \
  matrix_write(M, I[1]); \
  matrix_write_P(M, PSTR("\n")); \
  matrix_write(M, I[2]);\
}

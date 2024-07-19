# Commands

```
qmk setup
qmk config user.keyboard=splitkb/aurora/sofle_v2/rev1
qmk config user.keymap=SudoerWithAnOpinion
```

# New Keymap
`qmk new-keymap -kb splitkb/aurora/sofle_v2/rev1`

## Compile
`qmk compile -kb splitkb/aurora/sofle_v2/rev1 -km SudoerWithAnOpinion -e CONVERT_TO=liatris -j 24`

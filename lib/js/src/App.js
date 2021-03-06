// Generated by BUCKLESCRIPT VERSION 2.1.0, PLEASE EDIT WITH CARE
'use strict';

var Block                    = require("bs-platform/lib/js/block.js");
var Timeline                 = require("./Timeline.js");
var ReasonReact              = require("reason-react/lib/js/src/ReasonReact.js");
var View$BsReactNative       = require("bs-react-native/lib/js/src/components/view.js");
var Style$BsReactNative      = require("bs-react-native/lib/js/src/style.js");
var StyleSheet$BsReactNative = require("bs-react-native/lib/js/src/styleSheet.js");

var styles = StyleSheet$BsReactNative.create({
      wrapper: Style$BsReactNative.style(/* :: */[
            Style$BsReactNative.flex(1),
            /* :: */[
              Style$BsReactNative.marginTop(/* Pt */Block.__(0, [50])),
              /* :: */[
                Style$BsReactNative.marginBottom(/* Pt */Block.__(0, [30])),
                /* :: */[
                  Style$BsReactNative.marginLeft(/* Pt */Block.__(0, [30])),
                  /* :: */[
                    Style$BsReactNative.marginRight(/* Pt */Block.__(0, [30])),
                    /* [] */0
                  ]
                ]
              ]
            ]
          ])
    });

function app() {
  return ReasonReact.element(/* None */0, /* None */0, View$BsReactNative.make(/* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* Some */[styles.wrapper], /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0, /* None */0)(/* array */[ReasonReact.element(/* None */0, /* None */0, Timeline.make(/* array */[]))]));
}

exports.styles = styles;
exports.app    = app;
/* styles Not a pure module */

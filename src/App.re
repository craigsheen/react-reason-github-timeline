open BsReactNative;

let styles =
  StyleSheet.create(
    Style.({"wrapper": style([flex(1.), marginTop(Pt(50.)), marginBottom(Pt(30.)), marginLeft(Pt(30.)), marginRight(Pt(30.))])})
  );

let app = () =>
  <View style=styles##wrapper>
    <Timeline/>
  </View>;

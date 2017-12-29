open BsReactNative;

let styles =
  StyleSheet.create(
    Style.({"timelineItem": style([flex(1.), paddingBottom(Pt(20.)), paddingTop(Pt(20.)), borderBottomWidth(1.)]), "user": style([alignItems(Center), flexDirection(Row), marginBottom(Pt(10.))]), "userImage": style([height(Pt(50.)), marginRight(Pt(20.)), width(Pt(50.))]), "userName": style([fontSize(Float(20.))]), "repoName": style([fontSize(Float(16.))])})
  );

let component = ReasonReact.statelessComponent("TimelineItem");

let openLink = (url:string) => {
  Linking.openURL(url) |> ignore
};

let make = (~timelineItem: TimelineItemData.timelineItem, _children) => {
  let body = (switch(timelineItem.body) {
    | Some(body) => body
    | None => ""
  });
  let eventLink = (switch(timelineItem.eventLink) {
    | Some(eventLink) => eventLink
    | None => ""
  });
  {
  ...component,
  render: (_self) =>
    <View style=styles##timelineItem>
      <TouchableOpacity style=styles##user onPress=(() => openLink("https://github.com/"++timelineItem.username))>
        <Image style=styles##userImage source=(URI(Image.(imageURISource(~uri=timelineItem.userImage, ())))) />
        <Text style=styles##userName value=(timelineItem.username) />
      </TouchableOpacity>
      <TouchableOpacity onPress=(() => openLink("https://github.com/"++timelineItem.repo))>
        <Text style=styles##repoName value=("repo: "++timelineItem.repo) />
      </TouchableOpacity>
      <TouchableOpacity onPress=(() => openLink(eventLink))>
        <Text value=(body) />
      </TouchableOpacity>
    </View>
  }
};

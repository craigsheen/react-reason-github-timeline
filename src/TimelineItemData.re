module Option = {
  let unwrapUnsafely = (data) =>
    switch data {
    | Some(v) => v
    | None => raise(Invalid_argument("unwrapUnsafely called on None"))
    };
};

type timelineItem = {
  id: string,
  eventType: string,
  username: string,
  userImage: string,
  repo: string,
  body: option(string),
  eventLink: option(string)
};

let buildTimelineItem = (timelineItemJson): timelineItem => {
  Json.Decode.{
    id: timelineItemJson |> field("id", string),
    eventType: timelineItemJson |> field("type", string),
    username: timelineItemJson |> at(["actor", "display_login"], string),
    userImage: timelineItemJson |> at(["actor", "avatar_url"], string),
    repo: timelineItemJson |> at(["repo", "name"], string),
    body: timelineItemJson |> optional(at(["payload", "comment", "body"], string)),
    eventLink: timelineItemJson |> optional(at(["payload", "comment", "html_url"], string))
  }
};

let fetchTimelineItems = () =>
  Js.Promise.(
    Fetch.fetch("https://api.github.com/users/craigsheen/received_events")
    |> then_(Fetch.Response.json)
    |> then_((json) => Js.Json.decodeArray(json) |> resolve)
    |> then_((opt) => Option.unwrapUnsafely(opt) |> resolve)
    |> then_(
       (timelineItems) =>
         timelineItems
         |> Js.Array.map((timelineItem) => buildTimelineItem(timelineItem))
         |> resolve
     )
);
